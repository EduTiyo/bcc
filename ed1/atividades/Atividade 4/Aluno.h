#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Aluno{
    private:
        string ra;
        string nome;
    public:
        Aluno(){
            this->nome = "undefined";
            this->ra = "0";
        }
        Aluno(string _ra, string _nome){
            this->nome = _nome;
            this->ra = _ra;
        }
        ~Aluno();
};