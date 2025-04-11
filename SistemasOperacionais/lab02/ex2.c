/*
  Descrição: Faça um programa que receba como entrada um comando (p. ex. ls, ping, ...) via terminal e execute
como seu filho. O processo pai deve aguardar o término da execução do comando.
  Autores:  Eduardo Knabben Tiyo          RA:2551748
            Pedro Chouery Grigolli        RA:2551845
            Felipe Martins Sanches        RA:2390809
            Ingrid Reupke Sbeguen Moran   RA:2349388 

  Data de criação: 10/04/2025
  Última data de alteração: 11/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // fork()
#include <sys/types.h> // pid_t
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]){

  int status;                                            // status do filho para esperar terminar o processo
  printf("DEPOIS DA EXECUÇÃO DO PROGRAMA DO FILHO\n\n"); // print para mostrar antes da execução do filho
  pid_t pid = fork();                                    // criação do filho 
  
  if(!pid) {                                             // se é o filho
    printf("COMANDO: ");
    char *flags[argc];                                 // vetor de vetor com comando, argumentos e, posteriormente, NULL
    for (int i = 1; i < argc; i++) {                   // laço de repetição para pegar os comandos e argumentos do terminal e colocar em flags
      flags[i-1] = argv[i];                            // flag recebe o comando/argumento da iteração
      printf("%s ", argv[i]);                       // print para mostrar o comando/argumento
    }
    printf("\n");
    fflush(stdout);
    flags[argc - 1] = NULL;                            // último elemento deve ser NULL para execvp
    execvp(argv[1], flags);                            // filho executa o comando com os argumentos
    exit(0);
    }
    if(wait(&status)>=0){                                // pai espera o filho terminar o processo
      printf("\nDEPOIS DA EXECUÇÃO DO PROGRAMA DO FILHO\n"); // print para mostrar depois da execução do filho
    }
  
  return 0;
}
