/*
  Faça uma interface de shell simples que fornece um prompt ao usuário para executar comandos do shell
  do sistema. Se o comando for executado em segundo plano (&), a interface deve possibilitar a execução
  de outros comandos. Caso contrário, a interface deve esperar o retorno do comando e, em seguida,
  exibir o prompt novamente.
  Autores:  Eduardo Knabben Tiyo          RA:2551748
            Pedro Chouery Grigolli        RA:2551845
            Felipe Martins Sanches        RA:2390809
            Ingrid Reupke Sbeguen Moran   RA:2349388 

  Data de criação: 15/04/2025
  Última data de alteração: 15/04/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 100

int main() {
  char input[MAX_INPUT];
  char *args[MAX_ARGS];
  pid_t pid;
  int background;

  while (1) {
    // exibe o prompt
    printf("> ");
    fflush(stdout); // garante que o prompt seja exibido imediatamente

    // lê a entrada do usuário
    fgets(input, MAX_INPUT, stdin);

    // remove o caractere de nova linha
    input[strcspn(input, "\n")] = '\0';

    // divide a entrada em argumentos
    int i = 0;
    char *token = strtok(input, " ");
    while (token != NULL) {
      args[i++] = token;
      token = strtok(NULL, " ");
    }
    args[i] = NULL; // termina a lista de argumentos

    // verifica se o comando deve ser executado em segundo plano
    background = 0;
    if (i > 0 && strcmp(args[i - 1], "&") == 0) {
      background = 1;
      args[i - 1] = NULL; // remove o & dos argumentos
    }

    // sai do shell se o comando for "exit"
    if (args[0] != NULL && strcmp(args[0], "exit") == 0) {
      break;
    }

    // cria um processo filho para executar o comando
    pid = fork();

    if (pid == 0) {
      // processo filho
      if (execvp(args[0], args) == -1 && strcmp(args[0], "exit") != 0) {
        printf("Erro ao executar o comando: %s\n", args[0]); // erro ao executar
      }
    } else {
      // processo pai
      if (!background) {
        //espera o processo filho terminar se não for em segundo plano
        waitpid(pid, NULL, 0);
      }
    }
  }

  return 0;
}