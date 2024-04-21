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

    Aluno a3("a345", "vitin");
    Aluno a4("a346", "dubar");
    Aluno a5("a347", "cesao");
    Aluno a6("a348", "tv");
    Aluno a7("a349", "ian");
    Aluno a8("a350", "eiki");
    Aluno a9("a351", "xulia");
    Aluno a10("a352", "miguel");

    Turma* t1 = new Turma("BCC3001", "IC3A", 10);
    // t1.imprimir();

    t1->matricula(a1);
    t1->matricula(&a2);
    t1->matricula(&a3);
    t1->matricula(&a4);
    t1->matricula(&a5);
    t1->matricula(&a6);
    t1->matricula(&a7);
    t1->matricula(&a8);
    t1->matricula(&a9);
    t1->matricula(&a10);
    t1->imprimirAlunos();
    t1->cancelarMatricula("a352");
    t1->cancelarMatricula("a345");
    t1->cancelarMatricula("a234");
    t1->cancelarMatricula("a346");
    t1->cancelarMatricula("a347");

    cout << endl;
    // t1->cancelarMatricula("a345");
    // t1->cancelarMatricula("a123");

    t1->imprimirAlunos();

    delete a1;
    delete t1;

    return 0;
}