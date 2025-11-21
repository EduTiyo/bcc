#include <iostream>

using namespace std;

class AB{
    public:
      AB* esquerda;
      AB* direita;
      AB* pai;
      int chave;
      AB(int chave){
        this->esquerda = nullptr;
        this->direita = nullptr;
        this->pai = nullptr;
        this->chave = chave;
      }
};

int main(){

    AB *a1 = new AB(1);
    

    return 0;
}