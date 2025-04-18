/*
  Faça um programa que processe um vetor e divida para N filhos partes iguais de processamento para
  localizar um item. Cada filho deve exibir seu PID e a posição que o item foi localizado. Um mesmo
  filho pode encontrar o item em mais de uma posição. Se nenhum filho localizar, o pai deve exibir a
  mensagem não encontrado
  Autores:  Eduardo Knabben Tiyo          RA:2551748
            Pedro Chouery Grigolli        RA:2551845
            Felipe Martins Sanches        RA:2390809
            Ingrid Reupke Sbeguen Moran   RA:2349388 

  Data de criação: 15/04/2025
  Última data de alteração: 15/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h> // pid_t
#include <unistd.h>    // fork()
#include <sys/wait.h>  // waitpid

void filhosBusca(int vetor[], int n, int quantidadeFilhos, int alvo){
  pid_t pids[quantidadeFilhos]; // vetor para armazenar os PIDs dos filhos
  int encontrado = 0; // flag para indicar se o valor foi encontrado
  int status; // status para o wait
  int parcela = n / quantidadeFilhos; // tamanho de cada parte do vetor
  
  for(int i = 0; i < quantidadeFilhos; i++){ // cria os filhos e busca no intervalo que será dado

    int inicio = i * parcela; // calcula o início do intervalo
    int fim;
    
    if (i == quantidadeFilhos - 1) { // se é o último filho, pega o restante do vetor
      fim = n;                       
    } else {                         // senão pega o intervalo normal
      fim = inicio + parcela;
    }
    
    pid_t pid = fork(); // cria o filho
    
    // código do filho
    if (pid == 0) { 
      int achouLocal = 0; // flag local para indicar se este filho encontrou o valor
      
      for (int j = inicio; j < fim; j++) { // filho percorre o intervalo buscando o alvo
        if (vetor[j] == alvo) { // se achou, imprime o PID e a posição
          printf("Filho PID %d encontrou o valor %d na posição %d\n", getpid(), alvo, j);
          achouLocal = 1; // atualiza flag para indicar que encontrou
        }
      }     
      exit(achouLocal); // retorna 1 se encontrou, 0 caso contrário
    }
    else {
      // código do pai - guarda o PID do filho no vetor
      pids[i] = pid;
    }
  }
  
  // pai espera todos os filhos terminarem
  for (int i = 0; i < quantidadeFilhos; i++) {
    waitpid(pids[i], &status, 0); // status será 1 se o filho encontrou o valor, 0 caso contrário
    
    // verifica o código de saída para saber se este filho encontrou o valor
    if (WIFEXITED(status) && WEXITSTATUS(status) == 1) {
      encontrado = 1; // atualiza flag para indicar que pelo menos um filho encontrou o valor
    }
  }
  
  // se nenhum filho encontrou o valor
  if (!encontrado) {
    printf("Pai: Valor %d não foi encontrado por nenhum filho.\n", alvo);
  }
  
}

int main(int argc, char* argv[]) {
  int n = atoi(argv[1]); // recebe o tamanho do vetor via terminal

  // validação de pelo menos 1 elemento no vetor
  if (n <= 0) {
    printf("Tamanho do vetor inválido.\n");
    return 1;
  }

  int vetor[n]; // declara o vetor com o tamanho informado
  int quantidadeFilhos = atoi(argv[2]); // recebe a quantidade de filhos via terminal
  
  // validação de quantidade de filhos
  if (quantidadeFilhos <= 0) {
    printf("Quantidade de filhos inválida.\n");
    return 1;
  }
  if (quantidadeFilhos > n) {
    printf("Quantidade de filhos maior que o tamanho do vetor.\n");
    return 1;
  }

  int alvo = atoi(argv[3]); // recebe o valor alvo via terminal

  // inicializa o gerador de números aleatórios
  srand(time(NULL));

  // preenche o vetor com valores aleatórios e imprime
  printf("Vetor gerado: ");
  for (int i = 0; i < n; i++) {
    vetor[i] = rand() % 30; // valores aleatórios entre 0 e 30
    printf("%d ", vetor[i]);
  }
  printf("\n");
  printf("Valor alvo: %d\n", alvo); // imprime o valor alvo

  filhosBusca(vetor, n, quantidadeFilhos, alvo); // chama a função que cria os filhos e busca o valor

  return 0;
}