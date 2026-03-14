/*
  Descrição: Faça um programa com N threads que localiza um valor em um vetor de inteiros. O espaço de busca no
  vetor deve ser distribuído para as N threads.
  Autores:  Eduardo Knabben Tiyo          RA:2551748
            Pedro Chouery Grigolli        RA:2551845
            Felipe Martins Sanches        RA:2390809
            Ingrid Reupke Sbeguen Moran   RA:2349388 

  Data de criação: 22/04/2025
  Data da última atualização: 24/04/2025
*/

// Ao compilar, executar ./ex01 N_VETOR N_THREADS ALVO

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef struct {
    int *vetor; // ponteiro de vetor a ser buscado (compartilhado)
    int inicio; // índice de início de cada thread
    int fim; // índice de fim de cada thread
    int alvo; // alvo a ser buscado
    int id; // id da thread
    int *encontrado; // variável compartilhada para indicar se o valor foi encontrado
    pthread_mutex_t *mutex; // mutex para proteger a variável compartilhada
} ThreadArgs;

void* threadBusca(void* arg) {
    ThreadArgs *args = (ThreadArgs*) arg; // converte o argumento para o tipo correto
    
    // cada thread busca o valor no seu intervalo
    int achouLocal = 0;
    for (int i = args->inicio; i < args->fim; i++) {
        if (args->vetor[i] == args->alvo) {
            pthread_mutex_lock(args->mutex);  // mutex utilizado para nao haver concorrência entre as threads
            printf("Thread %d encontrou o valor %d na posição %d\n", args->id, args->alvo, i);
            pthread_mutex_unlock(args->mutex);
            achouLocal = 1;
        }
    }
    // se achou, atualiza a variável compartilhada
    if (achouLocal) {
        pthread_mutex_lock(args->mutex); // mutex utilizado para nao haver concorrência entre as threads
        *(args->encontrado) = 1;
        pthread_mutex_unlock(args->mutex);
    }
    pthread_exit(NULL); // encerra a thread
}

int main(int argc, char* argv[]) {

  // tamanho do vetor
    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Tamanho do vetor inválido.\n");
        return 1;
    }
    
    int vetor[n];
    
    // quantidade de threads
    int quantidadeThreads = atoi(argv[2]);
    if (quantidadeThreads <= 0) {
        printf("Quantidade de threads inválida.\n");
        return 1;
    }
    if (quantidadeThreads > n) {
        printf("Quantidade de threads maior que o tamanho do vetor.\n");
        return 1;
    }

    // valor alvo
    int alvo = atoi(argv[3]);

   // geração do vetor 
    srand(time(NULL)); 
    printf("Vetor gerado: ");
    // print do vetor
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 30; // números aleatórios entre 0 e 29
        printf("%d ", vetor[i]);
    }
    // print do valor alvo
    printf("\nValor alvo: %d\n", alvo);

    pthread_t threads[quantidadeThreads]; // vetor de threads
    ThreadArgs args[quantidadeThreads]; // vetor de argumentos para cada thread
    int encontrado = 0; // variável compartilhada para indicar se o valor foi encontrado
    pthread_mutex_t mutex; // mutex para proteger a variável compartilhada
    pthread_mutex_init(&mutex, NULL); // inicializa o mutex

    // lógica para dividir o vetor entre as threads
    int parcela = n / quantidadeThreads;
    for (int i = 0; i < quantidadeThreads; i++) {
        args[i].vetor = vetor;
        args[i].inicio = i * parcela;
        args[i].fim = (i == quantidadeThreads - 1) ? n : (i + 1) * parcela;
        args[i].alvo = alvo;
        args[i].id = i;
        args[i].encontrado = &encontrado;
        args[i].mutex = &mutex;
        pthread_create(&threads[i], NULL, threadBusca, &args[i]); // cria a thread
    }

    for (int i = 0; i < quantidadeThreads; i++) {
        pthread_join(threads[i], NULL); // espera a thread terminar
    }

    // verifica se o valor foi encontrado
    if (!encontrado) {
        printf("Nenhuma thread encontrou o valor %d.\n", alvo);
    }

    // libera os recursos
    pthread_mutex_destroy(&mutex);
    return 0;
}
