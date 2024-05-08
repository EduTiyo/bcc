#include <iostream>

using namespace std;

// typedef struct no {
//     int dado;
//     struct no* prox;
// } No;

class No{
    public:
      int dado;
      No* prox;
};

void printContigua(int* v, int tam){
    cout << "[";
    for (int i = 0; i < tam; i++)
    {
        cout << v[i];
        if (i < tam -1) cout << ",";
    }
    cout << "]";
}

void printEncadeada(No* n){
    if(n->prox == nullptr){
        cout << n->dado << endl;
        return;
    }
    cout << n->dado << ",";
    printEncadeada(n->prox);
}

int main(){

    int* organizacaoContigua = new int(3);
    organizacaoContigua[0] = 1;
    organizacaoContigua[1] = 2;
    organizacaoContigua[2] = 3;

    // printContigua(organizacaoContigua, 3);

    No* n1 = new No();
    No* n2 = new No();
    No* n3 = new No();

    n1->dado = 1;
    n1->prox = n2;
    n2->dado = 2;
    n2->prox = n3;
    n3->dado = 3;
    n3->prox = new No();
    n3->prox->dado = 4;
    n3->prox->prox = nullptr;

    printEncadeada(n1);

    return 0;
}