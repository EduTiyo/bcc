
#include <string>
#include <iostream>

using namespace std;

class No{
    public:
        int dado;
        No* prox;

        No();
        No(int e);
        No(int e, No* prox);
};

class ListaEncadeada{

    private:
        No* ultimo;
        No* primeiro;

    public:
        ListaEncadeada();

        // Insere o elemento e na última posição
        bool push_back(No* n);
        // Insere o elemento e na primeira posição
        bool push_front(No* n);
        // Insere o elemento e na posição pos
        bool insert(int pos, int e);

        // Remove o último elemento
        int pop_back();
        // Remove o primeiro elemento
        int pop_front();
        // Remove o elemento da posição pos e retorna o elemento removido
        int erase(int pos);


        // Retorna o primeiro elemento
        int front();
        // Retorna o último elemento
        int back();
        // Retorna o elemento da posição pos
        int at(int pos);

        // Torna a lista vazia
        void clear();

        // Verifica se o vetor está vazio
        bool empty();
        // Devolve a quantidade de elementos
        int size();
        // Substitui o elemento da posição pos pelo elemento e
        bool replace(int pos, int e);

        // Imprime todos os elementos no formato [1,2,3]
        void print(No* n);
        void setPrimeiro(No* n);
        void setUltimo(No* n);

    private:
	    // Dobrar a capacidade quando não houver mais espaço
	    // Reduzir a capacidade pela metade quando for inferior a 25% de ocupação
        void gerenciaCapacidade();        
};

ListaEncadeada::ListaEncadeada(){}
    
No::No(){}

No::No(int e){
    this->dado = dado;
}

No::No(int e, No* prox){
    this->dado = dado;
    this->prox = prox;
}

void ListaEncadeada::setPrimeiro(No* n){
    primeiro = n;
}

void ListaEncadeada::setUltimo(No* n){
    ultimo = n;
}


bool ListaEncadeada::push_back(No* n){
    
    ultimo->prox = n;
    return true;
}

bool ListaEncadeada::push_front(No* n){
    primeiro = n;
    return true;
}

void ListaEncadeada::print(No* n){
    if(n->prox == nullptr){
        cout << n->dado << endl;
        return;
    }
    cout << n->dado << " ";
}
