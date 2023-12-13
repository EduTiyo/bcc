#include <stdio.h>
#include <stdlib.h>

int* read_array(const char* filepath, int* n) {
    // Abre o arquivo para leitura binária
    FILE* file = fopen(filepath, "rb");

    if (file == NULL) {
        // Se não conseguir abrir o arquivo, exibe uma mensagem de erro e retorna NULL
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    // Obtém o tamanho do arquivo
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Calcula o número de elementos no vetor
    *n = file_size / sizeof(int);

    // Aloca memória na heap para o vetor
    int* vetor = (int*)malloc(file_size);

    if (vetor == NULL) {
        // Se a alocação falhar, exibe uma mensagem de erro e fecha o arquivo
        perror("Erro ao alocar memória para o vetor");
        fclose(file);
        return NULL;
    }

    // Lê o conteúdo do arquivo para o vetor
    fread(vetor, sizeof(int), *n, file);

    // Fecha o arquivo após a leitura
    fclose(file);

    printf("Vetor lido com sucesso do arquivo: %s\n", filepath);

    // Retorna o endereço do vetor alocado na heap
    return vetor;
}

int main() {
    // Exemplo de uso da função
    const char* filepath = "./dados/dadosbin.txt";
    int* vetor;
    int tamanho_vetor;

    vetor = read_array(filepath, &tamanho_vetor);

    if (vetor != NULL) {
        // Imprime o conteúdo do vetor
        printf("Conteúdo do vetor lido:\n");
        for (int i = 0; i < tamanho_vetor; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");

        // Libera a memória alocada para o vetor
        free(vetor);
    } else {
        printf("Falha ao ler o vetor do arquivo.\n");
    }

    return 0;
}
