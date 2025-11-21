/*
  Descrição: Faça um programa que crie uma hierarquia de processos com N níveis (1 + 2 + 4 + 8 + … + 2^N-1)
  processos. Visualize a hierarquia usando um comando do sistema (pstree).
  Autores:  Eduardo Knabben Tiyo          RA:2551748
            Pedro Chouery Grigolli        RA:2551845
            Felipe Martins Sanches        RA:2390809
            Ingrid Reupke Sbeguen Moran   RA:2349388 

  Data de criação: 11/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // fork()
#include <sys/types.h> // pid_t

void criar_n_niveis_filhos(int n){
  n--;
  pid_t pidA = fork();              // pai cria um filho
  if(pidA) {                        // verifica se é o pai (pidA != 0)
    pid_t pidB = fork();            // cria o segundo filho
    if(!pidB) {                     // verifica se é o filho recém-criado
      if(n > 0) {                   // verifica se o nível ainda é maior que 0
        criar_n_niveis_filhos(n-1); // função recursiva em que o segundo filho vira pai e cria mais filhos
      } 
    } 
  }
  else{                           // verifica se é o primeiro filho criado (!pidA)
    if(n > 0){                    // verificação de nível maior que 0
      criar_n_niveis_filhos(n-1); // função recursiva em que o primeiro filho vira pai e cria mais filhos
    }
  }
}

int main(int argc, char *argv[]){
  int n = atoi((argv[1]));                  // Recebe quantidade de níveis por terminal.
  printf("Quantidade de níveis: %d \n", n); // exibe a quantidade de níveis
  printf("PID do pai: %d\n", getpid());     // exibe o PID do pai
  n--;                                      // desconta o nível antes de começar a criar filhos, pois o pai também conta como nível

  if(n > 0){                                // verifica se o nível é maior que 0 (não ser apenas o pai)
    criar_n_niveis_filhos(n);               // chamada da função que cria n-1 níveis de filhos
  }

  getchar();                                // função utilizada apenas para o programa nao terminar e a árvore de processos poder ser exibida no pstree
}