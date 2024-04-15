#include "class.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    Aluno* a1 = new Aluno();
    a1->setRa("a123");
    a1->setNome("dudu");
    // a1->imprimir();

    Aluno a2;
    a2.setRa("a234");
    a2.setNome("bornia");
    // a2.imprimir();

    Aluno a3("a345", "grigo");

    Turma* t1 = new Turma("BCC3001", "IC3A", 100);
    // t1.imprimir();

    t1->matricula(a1);
    t1->matricula(&a2);
    t1->matricula(&a3);
    t1->imprimirAlunos();

    cout << endl;

    t1->cancelarMatricula("a345");
    t1->cancelarMatricula("a123");

    t1->imprimirAlunos();

    delete a1;
    delete t1;

    return 0;
}