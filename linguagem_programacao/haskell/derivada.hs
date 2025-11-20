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
derivar (Const _) c = Const 0
derivar (Var x) c = if x == c then Const 1 else Const 0
derivar (Soma u v) c = Soma (derivar u c) (derivar v c)
derivar (Produto u v) c = Soma (Produto (derivar u c) v) (Produto u (derivar v c))
derivar (Potencia u n) c = Produto (Produto (Const n) (Potencia u (n - 1))) (derivar u c)

--------------Simplificação--------------

--simplificar :: Expressao -> Expressao


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
    let prefixa = "(^ (+ x 1) 2)"
    let parse_out  = parse (tokenize prefixa)
    let expr = fst parse_out
    let derivada = derivar expr "x"
    putStrLn $ "Expressão original: " ++ imprimir expr
    putStrLn $ "Derivada em relação a x: " ++ imprimir derivada