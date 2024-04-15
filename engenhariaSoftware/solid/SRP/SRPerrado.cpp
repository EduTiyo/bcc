#include <iostream>
#include <string>

using namespace std;

class Aluno{
    private:
      string name;
      string ra;
    public:
      void cadastrarAlunoErrado(string name, string ra){
        this->name = name;
        this->ra = ra;
        cout << this->name << ", " << this->ra << endl;
      }


};

int main(){
    Aluno a1;
    a1.cadastrarAlunoErrado("NomeAluno1", "a123");

    return 0;
}