#include <iostream>
#include <string>
using namespace std;

class Aluno
{
    private:
        string ra;
        string nome;

    public:
        Aluno(){
            this->ra = "0"; // posso criar outro construtor caso nao tenha nenhum parametro
            this->nome = "undefined";
        }
        Aluno(string ra, string nome){
            this->ra = ra;
            this->nome = nome;
        }
        ~Aluno(){
            cout << "destruindo" << endl;
        }
        string getRa(){
            return this->ra;
        }
        void setRa(string ra){
            this->ra = ra;
        }
        void imprimirAluno(){
            cout << "(" << this->ra << ", " << this->nome << ")" << endl;
        }
};
