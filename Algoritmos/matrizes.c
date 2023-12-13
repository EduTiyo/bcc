#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Escreva uma função que imprime o conteúdo de uma matriz.

void print_matrix(int rows, int cols, int m[rows][cols]){

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%02d ", m[i][j]);
        }
        printf("\n");
        
    }   
}

// 2. Escreva uma função que imprime o conteúdo de uma matriz ao contrário, isto é, do último elemento
// para o primeiro. Considerando a matriz do exemplo anterior, a função imprimiria do 9 ao 1.

void print_reversed(int rows, int cols, int m[rows][cols]){

    for (int i = rows-1; i >= 0; i--){
        for (int j = cols-1; j >= 0; j--){

            printf("%02d ", m[i][j]);
        }
        printf("\n");

    }
}

// 3. Escreva uma função que encontra e imprime o maior e o menor valores contidos em uma matriz.
void print_min_max(int rows, int cols, int m[3][3]){

    int max=m[0][0];
    int min=m[0][0];

    for (int i=0; i<rows; i++){

        for(int j = 0; j<cols; j++){

            if (m[i][j] >= max)
                max = m[i][j];
            
            if (m[i][j] <= min)
                min = m[i][j];
        }
    }
    printf("min: %d\nmax: %d\n", min, max);
}

// 4. Escreva uma função que retorna a média aritmética simples de todos os elementos da matriz.
float average(int rows, int cols, int m[3][3]){

    float sum = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum+=m[i][j];
        }
    }
    float average = sum/(rows*cols);
    return average;
    
}

// 5. Escreva uma função que inicia uma matriz com valores inteiros, iniciando em start e progredindo
// com step.
void init_values(int rows, int cols, int m[rows][cols], int start, int step){

    m[0][0]=start;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i==0 && j==0)
                continue;
            if (i>0 && j==0){

                m[i][j] = m[i-1][cols-1] + step;
            }
            else
                m[i][j] = m[i][j-1] + step;
        }
        
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }  
}

// 6. Escreva uma função que inicia uma matriz com valores aleatórios, sorteados entre min e max, isto
// é [min..max]. Utilize a função rand() da biblioteca <stdlib.h> para obter os valores:
void init_random(int rows, int cols, int m[rows][cols], int min, int max){

    for (int  i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m[i][j] = min + rand() % max-min+1;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// 7. Escreva uma função que retorna o total da linha de maior soma em uma matriz. A função deve
// somar todos os elementos em cada linha da matriz, para então encontrar a linha de maior soma.
int max_line(int rows, int cols, int m[rows][cols]){

    int max = m[0][0];
    int sum=0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum+=m[i][j];
        }
        if (sum >= max)
            max=sum;
        sum=0;
    }
    return max;
    
}

// 8. Escreva uma função que recebe uma matriz e coloca as somas de cada linha na última coluna.
void put_totals(int rows, int cols, int m[rows][cols]){

    int jota=0;
    for (int i = 0; i < rows; i++)
    {
        int sum=0;
        for (int j = 0; j < cols-1; j++)
        {
            sum += m[i][j];
            jota = j;
        }
        m[i][jota+1] = sum;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
}

// 9. Escreva uma função que verifica a igualdade entre duas matrizes. Ele deve retornar 1 (true) se as
// matrizes forem iguais ou 0 (false), caso sejam diferentes. Matrizes iguais possuem os mesmos
// elementos e as mesmas dimensões.
int matrix_equals(int r1, int c1, int m1[r1][c1], int r2, int c2, int m2[r2][c2]){

    if (r1 != r2 || c1 != c2){
        return 0;
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            if (m1[i][j]!=m2[i][j])
                return 0;
        }
        
    }
    return 1;
    
}

// 10. Escreva uma função que realiza a adição de duas matrizes m1 e m2, colocando o resultado em
// m3. Considere que todas as matrizes possuem as mesmas dimensões (rows x cols).
void sum(int rows, int cols, int m1[rows][cols], int m2[rows][cols], int m3[rows][cols]){

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", m3[i][j]);
        }
        printf("\n");
    }
}

// 11. Escreva uma função que monta a transposta da matriz m1 em m2. Observe que deve haver uma
// compatibilidade entre as dimensões das matrizes.
void transpose(int rows, int cols, int m1[rows][cols], int mt[cols][rows]){

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            mt[j][i] = m1[i][j];
        }
        
    }
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }
}

// 12. Escreva uma função que troca as diagonais de uma matriz. Considere que a matriz é quadrada,
// com dimensões d.
void switch_diagonals(int d, int m[d][d]){
    int temp;
    for (int i = 0, j = d-1; i < d; i++, j--)
    {
        temp = m[i][i];
        m[i][i] = m[i][j];
        m[i][j] = temp;
    }
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("%02d ", m[i][j]);
        }
        printf("\n");
    }
    
    
}


// 13. Escreva uma função que cria o Triângulo de Pascal em uma matriz e depois o imprime. A função
// deve receber o número de linhas desejado para o triângulo.
void pascal_triangle(int n){

    int m[n][n+1];
    m[0][1]=1;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            m[i][j]=0;
        }
        
    }
    
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            m[i+1][j+1] = m[i][j] + m[i][j+1];
        }
        
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
        
    }
}

// 14. Escreva uma função que verifica se uma matriz contém um triângulo superior e devolve 1 (true) ou
// 0 (false). Considere que a matriz é quadrada, com dimensões d. Dica: nesta matriz, todos os
// elementos do triângulo esquerdo inferior, nos quais row > col, devem ser iguais a zero.
int check_upper_triangle(int d, int m[d][d]){

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (i>j && m[i][j] != 0)
            {
                return 0;
            }
            
        }
        
    }
    return 1;
}


// 15. Escreva uma função que verifica se uma matriz é identidade e devolve 1 (true) ou 0 (false).
int check_identity(int rows, int cols, int m[rows][cols]){

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i==j && m[i][j]!=1)
                return 0;
            else if (i!=j && m[i][j]!=0)
                return 0;
        }
        
    }
    return 1;
}

// 16. Escreva uma função que verifica se uma matriz é simétrica e devolve 1 (true) ou 0 (false). Em uma
// matriz simétrica os valores são espelhados em relação à diagonal principal. Considere que a matriz
// é quadrada, com dimensões d
int check_symetric(int d, int m[d][d]){

    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (m[i][j] != m[j][i])
            {
                return 0;
            }
            
        }
    }
    return 1;
}

// 17. Escreva uma função que imprime um array de n strings de até len-1 letras.
void print_strings(int n, int len, char list[n][len]){

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; list[i][j] != 0; j++)
        {
            printf("%c", list[i][j]);
        }
        printf("\n");
    }
}

// 18. Escreva uma função que imprime as palavras de maior e menor tamanhos em um array de n
// strings de até len-1 letras.
void print_strings_minmax(int n, int len, char list[n][len]){

}

// 19. Escreva uma função que retorna a quantidade de palavras em um array de n linhas de texto
// (strings de até len-1 letras). Considere que poderá haver mais de um espaço entre cada palavra,
// bem como, espaços no início ou final de cada string.
int count_words(int n, int len, char lines[n][len]){

    int words = 0;
    int flag = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; lines[i][j] != 0; j++)
        {
            if (((lines[i][j] > 64 && lines[i][j] < 91) || (lines[i][j] > 96 && lines[i][j] < 123)) && flag == 0){

                flag = 1;

            }
            else if ((lines[i][j] == 32 || lines[i][j] == 44 || lines[i][j]  == 46) && flag == 1){

                flag = 0;
                words+=1;

            }
        }
            flag = 0;
        
    }
    return words;
}

// 20. Escreva uma função que conta e devolve o número de ocorrências de uma palavra word em um
int countOcorrences(int rows, int columns, char lines[rows][columns], char word[]){
    int ocorrences = 0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            if(lines[i][j-1] == ' ' || lines[i][j-1] == 0){
                for(int k = 0; word[k] != 0; k++){
                    if(lines[i][j] != word[k]) break;
                    if(word[k+1] == 0) ocorrences++;
                    j++;
                }  
            }
        }
    }
    return ocorrences;
}

int main(){
    /* ex 1 */
    int m [3][3]= {
        {1,2,3},
        {4,12,6},
        {7,8,10}
    };
    print_matrix(3,3, m);
    // -----------------------------

    /* ex 2 */
    // int m [3][3]= {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };
    // print_reversed(3,3, m);
    // ----------------------------------

    /* ex 3 */
    // int m [3][3]= {
    //     {13, -30,4},
    //     {10,-1,0},
    //     {14,5,-2}
    // };
    // print_min_max(3,3, m);

    /* ex 4 */
    // int m [3][3]= {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };
    // printf("\n%.2f\n\n", average(3,3, m));

    /* ex 5 */
    // int v[4][6];
    // init_values(4,6,v,10,2);

    /* ex 6 */
    // int v[4][6];
    // init_random(4, 6, v, 1,1);

    /* ex 7 */
    // int v[5][5]={
    //     {1,2,3,4,5},
    //     {2,4,6,8,10},
    //     {1,2,3,4,7},
    //     {2,0,6,1,10},
    //     {7,3,4,0,0}
    // };
    // int res = max_line(5, 5, v);
    // printf("\nmaior soma: %d\n\n", res);

    /* ex 8 */
    // int mat[4][5] = {
    // { 1, 2, 3, 4, 0},
    // { 2, 4, 6, 8, 0},
    // { 3, 6, 9, 12, 0},
    // { 4, 8, 12, 16, 0}
    // };
    // put_totals(4, 5, mat);

    /* ex 9 */
    // int m1[2][3]={
    //     {1,2,3},
    //     {1,2,3}
    // };
    // int m2[2][3]={
    //     {1,2,3},
    //     {1,2,3}
    // };
    // printf("\n%d \n\n", matrix_equals(2,3,m1,2,3,m2));

    /* ex 10 */
    // int m1 [3][2] = {
    //     {1,3},
    //     {1,0},
    //     {1,2}
    // };
    // int m2 [3][2] = {
    //     {0,0},
    //     {7,5},
    //     {2,1}
    // };
    // int m3 [3][2]={0};
    // sum(3,2,m1,m2,m3);

    /* ex 11 */
    // int m1[2][3] = {

    //     {1,2,3},
    //     {0,-6,7}
    // };
    // int mt[3][2] = {0};
    // transpose(2,3,m1,mt);

    /* ex 12 */
    // int m[4][4] = {
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12},
    //     {13,14,15,16}
    // };
    // switch_diagonals(4, m);

    // /* ex 13 */
    // pascal_triangle(6);

    /* ex 14 */
    // int m[3][3] = {
    //     {1,2,3},
    //     {1,5,6},
    //     {0,0,7}
    // };
    // printf("\n%d\n\n", check_upper_triangle(3, m));

    /* ex 15 */
    // int m[3][3] = {
    //     {1,0,0},
    //     {0,0,0},
    //     {0,0,1}
    // };
    // printf("\n%d\n\n", check_identity(3, 3, m));
    // return 0;
    
    /* ex 16 */
    // int m[3][3] = {
    //     {1,2,3},
    //     {2,4,5},
    //     {3,5,8}
    // };    
    // printf("\n%d\n\n", check_symetric(3, m));

    /* ex 17 */
    // char v[6][20] = {"Johnny", "Mariane", "Jak", "Samuel", "Ada", "Michelangelo"};
    // print_strings(6,20,v);

    /* ex 18 */
    
    /* ex 19 */
    // char v[2][200] = {

    //     " Computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
    //     " Programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language."
    // };
    // int counter = count_words(2, 200, v);
    // printf("\n%d\n\n", counter);

    /* ex 20 */
    // char v[2][200] = {

    //     " Computer programming is the process of designing and building an executable computer program for accomplishing a specific computing task.",
    //     " Programming involves tasks such as analysis, generating algorithms, profiling algorithms accuracy and resource consumption, and the implementation of algorithms in a chosen programming language."
    // };
    // char word[]="is";
    // int counter = countOcorrences(2,200,v,word);
    // printf("\n%d\n\n", counter);
        
}
