#include <iostream>
#include <string>
using namespace std;

typedef struct aluno
{
    string ra;
    string nome;
} Aluno;

Aluno* alunoCriar(string ra, string nome);
void alunoImprimir(Aluno* aluno);
void alunoDestruir(Aluno* aluno);
void alunoInicializar(Aluno* aluno, string ra, string nome);

Aluno* alunoCriar(string ra, string nome){
    // Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    Aluno* novo = new Aluno();
    alunoInicializar(novo, ra, nome);
    return novo;
}

void alunoImprimir(Aluno* aluno){
    cout << "(" << aluno->ra << ", " << aluno->nome << ")" << endl;
}
void alunoDestruir(Aluno* aluno){
    // free(aluno);
    delete aluno;
}

void alunoInicializar(Aluno* aluno, string ra, string nome){
    aluno->nome = nome;
    aluno->ra = ra;
}