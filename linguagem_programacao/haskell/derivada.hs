------------------------ Definição do tipo de dados ------------------------
-- Tipo de Dado Algébrico para representar expressões matemáticas
data Expressao = 
    Const Int
    | Var String
    | Soma Expressao Expressao
    | Produto Expressao Expressao
    | Potencia Expressao Int
    deriving(Show, Eq)


------------------------ Função de pré-processamento ------------------------
-- Adiciona espaços ao redor de parênteses para facilitar a tokenização
adicionaEspacos :: Char -> [Char]
adicionaEspacos c = if c `elem` "()"
                    then " " ++ [c] ++ " "
                    else [c]

------------------------ Função de tokenização ------------------------
-- Espera uma expressão pré-fixa como string e retorna uma lista dos símbolos

tokenize :: String -> [String]
tokenize s = words (concatMap adicionaEspacos s)

------------------------ Função de parsing ------------------------
-- Retorna a expressão e os tokens restantes
parse :: [[Char]] -> (Expressao, [[Char]])

parse ("(":tokens) =
    let 
        (op:tokens1) = tokens
    in 
        case op of
            "+" ->
                let 
                    (expr1, tokens2) = parse tokens1
                    (expr2, tokens3) = parse tokens2
                in 
                    (Soma expr1 expr2, tail tokens3)
            
            "*" ->
                let 
                    (expr1, tokens2) = parse tokens1
                    (expr2, tokens3) = parse tokens2
                in 
                    (Produto expr1 expr2, tail tokens3)

            "^" -> -- É uma potência
               let 
                    (expr1, tokens2) = parse tokens1
                   -- O segundo operando é um Int
                    (Const n, tokens3) = parse tokens2 -- Simplificação: assumindo n é Const
               in 
                    --(Potencia expr1 (round n), tail tokens3) -- tail consome o ")"
                    (Potencia expr1 n, tail tokens3) -- tail consome o ")"

            _   -> error "Operador desconhecido"

parse (token:resto) =
    case reads token :: [(Int, String)] of
        -- Tenta ler como um número
        [(val, "")] -> (Const val, resto)
        -- Se falhar, é uma variável
        _           -> (Var token, resto)


------------------------ Função de diferenciação ------------------------
-- Recebe uma expressão e a variável em relação à qual se deve derivar
-- Retorna a expressão derivada

derivar :: Expressao -> String -> Expressao

-- Regras de derivação

-- Constante
derivar (Const _) c = Const 0

-- Variável
derivar (Var x) c = if x == c then Const 1 else Const 0

-- Soma
derivar (Soma u v) c = Soma (derivar u c) (derivar v c)

-- Produto
derivar (Produto u v) c = Soma (Produto (derivar u c) v) (Produto u (derivar v c))

-- Potência
derivar (Potencia u n) c = Produto (Produto (Const n) (Potencia u (n - 1))) (derivar u c)

--------------Simplificação--------------

simplificar :: Expressao -> Expressao

-- Regras de simplificação básicas

-- Soma
simplificar (Soma (Const 0) b) = simplificar b
simplificar (Soma a (Const 0)) = simplificar a
simplificar (Soma (Const a) (Const b)) = Const (a + b)

-- Produto
simplificar (Produto (Const 0) b) = Const 0
simplificar (Produto a (Const 0)) = Const 0
simplificar (Produto (Const 1) b) = simplificar b
simplificar (Produto a (Const 1)) = simplificar a
simplificar (Produto (Const a) (Const b)) = Const (a * b)
simplificar (Produto (Const a) (Produto (Const b) c)) = simplificar (Produto (Const (a * b)) c)
simplificar (Produto (Produto (Const a) b) (Const c)) = simplificar (Produto (Const (a * c)) b)

-- Potência
simplificar (Potencia a 0) = Const 1
simplificar (Potencia a 1) = simplificar a
simplificar (Potencia (Const a) n) = Const (a ^ n)

-- Distribuição
simplificar (Produto a (Soma b c)) = simplificar (Soma (Produto a b) (Produto a c))
simplificar (Produto (Soma b c) a) = simplificar (Soma (Produto b a) (Produto c a))

-- Aplicar simplificações recursivamente
simplificar (Potencia a n) = Potencia (simplificar a) n
simplificar (Soma a b) = 
    let a' = simplificar a
        b' = simplificar b
        resultado = Soma a' b'
    in if resultado == Soma a b then resultado else simplificar resultado
simplificar (Produto a b) = 
    let a' = simplificar a  
        b' = simplificar b
        resultado = Produto a' b'
    in if resultado == Produto a b then resultado else simplificar resultado

simplificar expr = expr

-------------Imprimir Infixa----------------

imprimir :: Expressao -> [Char]
imprimir (Const n) = show n
imprimir (Var x) = x
imprimir (Soma a b) = "(" ++ imprimir a ++ " + " ++ imprimir b ++ ")"
imprimir (Produto a b) = "(" ++ imprimir a ++ " * " ++ imprimir b ++ ")"
imprimir (Potencia a n) = "(" ++ imprimir a ++ "^" ++ show n ++ ")"

---------------------------------------

-- No GHCi:
-- let prefixa = "(^ (+ x 1) 2)"
-- let parse_out  = parse (tokenize prefixa)
-- let expr = fst parse_out
-- simplificar (derivar expr "x")

main :: IO ()
main = do
    putStrLn "Digite uma expressão em notação pré-fixa: ('sair' para encerrar)"
    loop

loop :: IO ()
loop = do
    putStr "> "
    input <- getLine
    if input == "sair"
        then putStrLn "Encerrando."
        else do
            processarExpressao input
            putStrLn ""
            loop

processarExpressao :: String -> IO ()
processarExpressao input = do
    case parseExpressao input of
        Left erro -> putStrLn $ "Erro ao analisar a expressão: " ++ erro
        Right expr -> do
            putStrLn $ "Expressão original: " ++ imprimir expr
            let derivada = derivar expr "x"
            putStrLn $ "Derivada: " ++ imprimir derivada
            let simplificada = simplificar derivada
            putStrLn $ "Derivada simplificada: " ++ imprimir simplificada

parseExpressao :: String -> Either String Expressao
parseExpressao input =
    case parse (tokenize input) of
        (expr, []) -> Right expr
        (_, resto) -> Left $ "Tokens não processados: " ++ show resto
