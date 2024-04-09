#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno{
    private:
        string ra;
        string nome;
    public:
        Aluno();
        Aluno(string _ra, string _nome);
        ~Aluno();
        void imprimirAluno();
        void setRa(string _ra);
        void setNome(string _nome);
        string getRa();
        string getNome();
};