#include "Aluno.h"
#include <iostream>
#include <string>
#include <vector>

Aluno::Aluno(){
    this->nome = "undefined";
    this->ra = "0";
}
Aluno::Aluno(string _ra, string _nome){
    this->nome = _nome;
    this->ra = _ra;
}

void Aluno::setRa(string _ra){
    this->ra = _ra;
}

void Aluno::setNome(string _nome){
    this->nome = _nome;
}

string Aluno::getRa(){
    return this->ra;
}

string Aluno::getNome(){
    return this->nome;
}

void Aluno::imprimirAluno(){
    cout << "(" << this->getRa() << ", " << this->getRa() << ")";
}
