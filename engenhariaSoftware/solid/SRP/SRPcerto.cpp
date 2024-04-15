#include <iostream>
#include <string>

using namespace std;

class Aluno{
    private:
      string name;
      string ra;
    public:
      void cadastrarAlunoCerto(string name, string ra){
        this->name = name;
        this->ra = ra;
      }
      string getNome(){
        return this->name;
      }
      string getRa(){
        return this->ra;
      }
};
      
class Console{
  public:
    void imprimirAluno(Aluno a){
      cout << a.getNome() << ", " << a.getRa() << endl;
    }
};


int main(){
    Console c;
    Aluno a2;
    a2.cadastrarAlunoCerto("NomeAluno2", "a345");
    c.imprimirAluno(a2);

    return 0;
}