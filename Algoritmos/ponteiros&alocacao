#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


// 1. Escreva uma função que aloca na heap um array de inteiros de tamanho n, preenchido com zeros,
// e retorna seu endereço.
int* create_vector(int n){

    int* v = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    

    return v;
}

void printVector(int n, int* v){
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n\n");
}

// 2. Escreva uma função que receba um vetor de inteiros e seu tamanho n. A função deve retornar o
// endereço de um novo vetor, alocado na heap, contendo os max maiores elementos contidos no
// vetor original. OBS: você pode modificar o conteúdo do vetor original, se necessário.

int* get_largest(int n, int* v, int max){
    int* v1 = malloc(max* sizeof(int));
    int largest = v[0];
    int largest_idx = 0;
    
    for (int i = 0; i < max; i++)
    {
        largest = INT_MIN;
        for (int j = 0; j < n; j++)
        {
            if (largest < v[j]){
                largest = v[j];
                largest_idx = j;
            }
        }
        v1[i] = largest;
        v[largest_idx] = INT_MIN;
    }
    return v1;    
}

// 3. Escreva uma função que receba o endereço de uma string. A função deve retornar o endereço de
// uma cópia da string alocada na heap.

char* copy_string(const char* str){

    int i = 0;
    while (str[i] != 0){
        i++;
    }
    char* v1 = malloc(i * sizeof(int));
    
    for (int j = 0; j < i; j++)
    {
        v1[j] = str[j];
    }
    return v1;   
}

// 4. Escreva uma função que receba o endereço de uma string. A função deve retornar o endereço de
// uma cópia reversa da string alocada na heap.

char* copy_reverse(const char* str){

    int size = strlen(str);
    
    char* v1 = malloc((size+1) * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        v1[i] = str[size - 1 - i];
    }

    return v1;
}

// 5. Escreva uma função que concatene duas strings e retorne o resultado em uma nova string, alocada
// na heap.

char* concat_string(const char* str1, const char* str2){
    
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    char* v1 = malloc((size1 + size2 + 1) * sizeof(int));
    int k = 0;
    for (int i = 0; i < size1; i++)
    {
        v1[i] = str1[i];
        k++;
    }
    
    v1[k] = 32;
    k++;
    int i = 0;
    for (k, i; i < size2; k++, i++)
    {
        v1[k] = str2[i];
    }
    return v1;
}

// 6. Escreva uma função que realize a união entre dois vetores, retornado o resultado em um vetor
// alocado na heap.

int* unir(int n1, const int* v1, int n2, const int* v2){

    int size = n1+n2;
    int* v3 = malloc(size * sizeof(int));
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        v3[i] = v1[i];
        k++;
    }
    for (int j = 0; j < n2; j++)
    {
        v3[k] = v2[j];
        k++;
    }
    
    return v3;
}

// 7. Escreva uma função que realize a intersecção entre dois vetores, retornado o resultado em um
// vetor alocado na heap.

int* intersection(int n1, const int* v1, int n2, const int* v2){

    
    
    
}

int main(){

    /* ex 1 */
    
    // int* v = create_vector(5);
    // printVector(5, v);
    // free(v);

    /* ex 2 */

    // int v0[] = {6,10,2,1,2,3,9};
    // int* v1 = get_largest(7, v0, 5);
    // printVector(5, v1);
    // free(v1);

    /* ex 3 */

    // char v[] = {"eduardo tiyo aiusdfasiudfu"};
    // char* v1 = copy_string(v);
    // printf("%s\n", v1);
    // free(v1);
    
    /* ex 4 */

    // char* v = {"eduardo tiyo"};
    // char* v1 = copy_reverse(v);
    // printf("%s\n", v1);
    // free(v1);

    /* ex 5 */

    char* v1 = {"eduardo"};
    char* v2 = {"tiyo"};

    // char* v3 = concat_string(v1,v2);
    // printf("%s\n", v3);
    // free(v3);

    /* ex 6 */

    // int v1[] = {1,2,3,4};
    // int v2[] = {5,6,7,8};
    // int* v3 = unir(4,v1,4,v2);
    // printVector(8,v3);
    // free(v3);

    /* ex 7 */



    return 0;
}
