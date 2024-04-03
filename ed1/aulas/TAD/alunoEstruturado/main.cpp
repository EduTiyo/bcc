#include <iostream>
#include <string>
#include "aluno.h"

using namespace std;

int main(){
    Aluno* a1 = alunoCriar("a111", "Joao");
    Aluno* a2 = alunoCriar("a222", "maria");
    Aluno a3;

    alunoInicializar(&a3, "a333", "jose");

    alunoImprimir(a1);
    alunoImprimir(a2);
    alunoImprimir(&a3);

    alunoDestruir(a1);
    alunoDestruir(a2);
    // alunoDestruir(a3); nao esta alocado na heap
}