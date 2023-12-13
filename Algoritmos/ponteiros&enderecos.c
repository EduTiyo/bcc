#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. Escreva um programa em C que declara três variáveis (char, int e double) e imprime seus
// endereços.

void print_address(char* a1, int* a2, double* a3){

    printf("\nchar: %p\nint: %p\ndouble: %p\n\n", a1, a2, a3);
}

// 2. Escreva uma função que recebe o endereço de duas variáveis inteiras. A função deve somar os
// valores contidos nessas variáveis por meio de seus endereços, colocando o resultado na primeira.
// void add(int* a, int* b)

void add(int* a, int* b){

    *a+=*b;
}

// 3. Escreva uma função que recebe o comprimento e o endereço de um vetor, e imprime o seu
// conteúdo, sem utilizar o operador de índice [ ] para acessar os elementos do vetor.
// void print_vector(int n, const int* v)

void printVector(int n, const int* v){

    for (int i = 0; i < n; i++)
    {
        printf("%d ", *v);
        v++;
    }
    printf("\n");
    
}

// 4. Escreva uma função que recebe o comprimento e o endereço de um vetor, e imprime o seu
// conteúdo em ordem reversa, sem utilizar o operador de índice [ ] para acessar os elementos do
// vetor.
void print_vector_reverse(int n, const int* v){

    for (int i = 0; i < n-1; i++)
    {
        v++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *v);
        v--;
    }
    printf("\n");
}

// 5. Escreva uma função que recebe o comprimento e o endereço de um vetor. A função deve retornar,
// via parâmetros min e max, o maior e o menor valor contido no vetor. Você não deve utilizar o
// operador de índice [ ] para acessar os elementos do vetor.
// void get_min_max(int n, const int* v, int* min, int* max)

void printMinMax(int n, const int* v, int* min, int* max){

    for (int i = 0; i < n; i++)
    {
        if (*v < *min) *min = *v;
        if (*v > *max) *max = *v;
        v++;
    }
}

// 6. Escreva uma função que recebe as dimensões e o endereço de uma matriz (vetor bidimensional).
// A função deve imprimir seu conteúdo, sem utilizar o operador de índice [ ] para acessar os
// elementos da matriz.
void print_vector2D(int rows, int cols, const int* v){

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0d ", *v);
            v++;
        }
        printf("\n");
    }
    
}

// 7. Escreva uma função que recebe o endereço de uma string. A função deve concatenar, ao final da
// string original, uma barra vertical, seguida do conteúdo da string de forma invertida. Considere que
// o vetor possui comprimento suficiente para a adição dos novos caracteres. Você não deve utilizar o
// operador de índice [ ] para acessar os caracteres da string.
void make_mirrored(char* str){

    int j = 0;
    for (int i = 0; *str!=0; i++)
    {
        printf("%c", *str);
        str++;
        j++;
    }
    printf("|");
    for (j; j>=0; j--)
    {
        printf("%c", *str);
        str--;
    }
    printf("\n");
    
}



int main(){

    /* ex 1 */

    char a1 = 'a';
    int a2 = 12;
    double a3 = 123.4;
    print_address(&a1, &a2, &a3);

    /* ex 2 */

    // int a = 10;
    // int b = 12;
    // add(&a,&b);
    // printf("\n%d\n\n", a);

    /* ex 3 */

    // int v[] = {1,2,3,4,5};
    // printVector(5, v);

    /* ex 4 */

    // int v[]={1,2,3,4,5};
    // print_vector_reverse(5, v);

    /* ex 5 */

    // int v[] = {1,2,3,4,5,-1,10,3,90,-23};
    // int min = v[0];
    // int max = v[0];
    // printMinMax(10, v, &min, &max);
    // printf("\nmin: %d\nmax: %d\n\n", min, max);

    /* ex 6 */
    // int v[3][3] = {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };
    // print_vector2D(3,3,(int*)v);

    /* ex 7 */

    // char name[40] = "asdf asfd";
    // make_mirrored(name);

    return 0;
}
