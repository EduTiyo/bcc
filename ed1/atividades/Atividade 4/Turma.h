#include "Aluno.h"
#include <iostream>
#include <string>
#include <vector>

class Turma{
    private:
        string codigoDisciplina;
        string codigoTurma;
        string semestre = "2024-1";
    public:
        Turma(string _codigoDisciplina, string _codigoTurma);
        ~Turma();
        void realizarMatricula(Aluno _Aluno, Turma _Turma);
};