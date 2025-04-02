#include <iostream>
#include <string>
#include "aluno.h"

using namespace std;

void teste(){
}

int main(){

    // teste();
    // cout << "fim" << endl;

    Aluno* a1 = new Aluno("a111", "joao");
    Aluno* a2 = new Aluno("a222", "maria");
    Aluno a3("a333", "jose");


    a1->imprimirAluno();
    a2->imprimirAluno();
    a3.imprimirAluno();

    a1->setRa("a000");
    cout << a1->getRa() << endl;

    delete a1;
    delete a2;
}