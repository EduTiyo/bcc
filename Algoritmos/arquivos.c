#include <stdio.h>
#include <stdlib.h>

// 1. Escreva uma função que verifica se o arquivo de caminho informado existe (retorna 1). Caso
// contrário, retorna 0.

int fileExists(){

    FILE* file = fopen("./dados/dados3.txt", "r");
    if (file == NULL){
        return 0;
    }
    fclose(file);
    return 1;

}

// 2. Escreva uma função que receba um caminho de arquivo. Se o mesmo existir, faz nada. Se o
// arquivo não existir, tenta criá-lo. A função deve retornar 1 (um) caso arquivo exista ou tenha sido
// criado e, 0 (zero), caso contrário.

int checkOrCreate(const char *filepath){

    FILE* file = fopen(filepath, "r");
    if (file==NULL){
        file = fopen(filepath, "w");
        return 0;
    }
    fclose(file);
    return 1;
}

// 3. Escreva uma função que receba um caminho de arquivo e imprima seu conteúdo no terminal.
// Retorna 1 para sucesso ou 0, caso o arquivo não exista.

int printContent(const char *filepath){

    FILE* file = fopen(filepath, "r");
    if(file == NULL) return 0;

    int n = 20;
    char buffer[n];
    
    while(fgets(buffer, n, file) != NULL){
        printf("%s", buffer);
    }
    fclose(file);
    return 1;
    
}

// 4. Escreva uma função que receba um caminho de arquivo e retorna a quantidade de linhas de texto
// contidas no arquivo. Dica: o caractere '\n' define a quebra de linha no texto.

int countLines(const char *filepath){

    FILE* file = fopen(filepath, "r");

    int c = fgetc(file);
    int lines = 1;
    while (c != EOF){
        if(c == '\n') lines++;
        c = fgetc(file);
    }
    fclose(file);
    return lines;
}

// 5. Escreva uma função que receba um caminho de arquivo e escreva uma string no mesmo. A função
// deve (re)criar o arquivo especificado. Retorna 1 para sucesso ou 0, em caso de erro.

int saveString(const char *filepath, const char* text){

    FILE* file = fopen(filepath, "w+");
    if (file==NULL) return 0;
    fputs(text, file);
    fclose(file);
    return 1;
}

// 6. Escreva uma função que receba um caminho de arquivo e acrescenta uma string no mesmo. A
// função deve criar o arquivo especificado, caso não exista. Retorna 1 para sucesso ou 0, em caso
// de erro. Dica: observe o modo de abertura 'a' (slide no. 5 do material).

int concatString(const char *filepath, const char* text){

    FILE* file = fopen(filepath, "a+");
    if (file==NULL) return 0;
    fputs(text, file);
    fclose(file);
    return 1;
}

// 7. Escreva uma função que receba um caminho de arquivo e escreva linhas de strings no mesmo. Ela
// deve (re)criar o arquivo especificado. A função recebe um vetor de strings e cada uma deve ser
// escrita em uma linha do arquivo. Retorna 1 para sucesso ou 0, em caso de erro.

int addString(const char *filepath, const char** textLines){

    FILE* file = fopen(filepath, "w");

    while(*textLines != NULL){
        fprintf(file, "%s\n", *textLines);
        textLines++;
    }
    fclose(file);
    return 1;
}

// 8. Escreva uma função que receba um caminho de arquivo e retorna uma string (vetor de caracteres
// terminado em nulo) alocada em heap contendo o conteúdo do arquivo. Caso ocorra algum
// problema, retorna NULL.

char* getContent(const char *filepath){

    FILE* file = fopen(filepath, "r");

    int size = 0;
    int c = fgetc(file);
    while (c != EOF){
        size++;
        c = fgetc(file);
    }

    char* v = malloc(size * sizeof(char));
    file = fopen(filepath, "r");
    c = fgetc(file);
    while (c != EOF){
        fputc(c, *v);
        c = fgetc(file);
    }
    fclose(file);
    for (v; v != 0; v++)
    {
        printf("%c", *v);
    }
    free(v);
    
}

int main(){

    /* ex 1 */

    // printf("\n%d\n\n", fileExists());
    // return 0;

    /* ex 2 */

    // char filepath[] = "./dados/dados2.txt";
    // printf("\n%d\n\n", checkOrCreate(filepath));

    /* ex 3 */

    // char filepath[] = "./dados/dados.txt";
    // printf("\n%d\n\n", printContent(filepath));

    /* ex 4 */

    // char filepath[] = "./dados/dados.txt";
    // printf("\n%d\n\n", countLines(filepath));
    
    /* ex 5 */

    // char filepath[] = "./dados/dados.txt";
    // printf("\n%d\n\n", saveString(filepath, "eduardo"));

    /* ex 6 */

    // char filepath[] = "./dados/dados.txt";
    // printf("\n%d\n\n", saveString(filepath, "eduardo"));

    /* ex 7 */

    // const char *filepath = "./dados/dados.txt";
    // const char* text[] = {"eduardo", "knabben", "tiyo", NULL};
    // printf("\n%d\n\n", addString(filepath, text));

    /* ex 8 */

    const char *filepath = "./dados/dados.txt";
    getContent(filepath);
    

}
