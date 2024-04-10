#include <iostream>
#include <string>
#include <string.h>
using namespace std;
typedef struct{
    int codigo;
    char descricao[12];
    float preco;

} Produto;
int main(){

    Produto prodA = {1, "teclado", 98.5};
    Produto prodB = {2, "mouse", 65.00};
    Produto prodC = {3, "webcam", 130.00};
    Produto prodD = {4, "microfone", 250};

    Produto* vet[4];
    vet[0] = &prodA;
    vet[1] = &prodB;
    vet[2] = &prodC;

    vet[0]->codigo = 100;
    char desc[12] = "MouseSemFio";
    strcpy(vet[1]->descricao, desc);
    vet[3] = &prodD;
    
    return 0;
}