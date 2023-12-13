#include <stdio.h>
#include <string.h>

// 1. Escreva uma função que recebe uma string (como parâmetro) e a imprime na tela, com cada
// caractere separado por um espaço. Você não pode utilizar strlen()


void print_string(char str[]){

    for (int i = 0; str[i]!=0 ; i++)
    {
        printf("%c ", str[i]);
    }
    
}

// 2. Escreva uma função que recebe uma string e a imprime ao contrário (da direita para esquerda).
// Faça duas versões da função: uma utilizando strlen() <string.h>, e outra, sem utilizar a função.

void print_string_reversed(char str[]){

    for (int i = (strlen(str)-1); i >= 0; i--){

        printf("%c", str[i]);
    }
}

void print_string_reverser2(char str[]){

    int i = 0;
    while (str[i]!=0){
        i++;
    }
    for (i; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}    
//     3. Escreva uma função que recebe uma string e imprime seus caracteres separados por um outro
// caractere, fornecido como segundo parâmetro da função. Note que o separador não deve ser
// impresso ao final.;

void print_with_separator(char str[], char separator){

    for (int i = 0; str[i]!=0; i++)
    {
        printf("%c%c", str[i], separator);
    }
    
}

// 4. Escreva uma função que recebe uma string e imprime:
// a. A quantidade de letras (maiúsculas ou minúsculas);
// b. A quantidade de dígitos;
// c. A quantidade de símbolos.
// OBS: considere apenas a porção dos caracteres imprimíveis da tabela ASCII, isto
// é, dos índices 32 ao 126.


void string_report(char str[]){
    int letras=0;
    int simbolos=0;
    int i = 0;
    while (str[i]!=0){

        if (((int)str[i] >= 65 && (int)str[i] <= 90) || ((int)str[i] >= 97 && (int)str[i] <= 122)){

            letras++;
        }
        if ((int)str[i] >= 32 && (int)str[i] <= 64 || (int)str[i] >= 91 && (int)str[i] <= 96 || (int)str[i] >= 123 && (int)str[i] <= 126){

            simbolos++;
        }
        i++;
    }

    printf("%d letras \n%d digitos \n%d simbolos\n", letras, i, simbolos);

}

// 5. Escreva uma função que recebe uma string e a converte para letras maiúsculas. Atenção: a string
// poderá conter letras maiúsculas e símbolos.

void stringToUpper(char str[]){

    for (int i = 0; str[i] != 0; i++){

        if (str[i] >= 97 && str[i] <= 122){
            str[i]-=32;
        }
        printf("%c", str[i]);
    }
}

void main(){
    char str[]={"Ola mundo!!"};
    // print_string(str);
    // print_string_reversed(str);
    // print_string_reverser2(str);
    // print_with_separator(str, '$');
    // string_report(str);
    stringToUpper(str);
}
