
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
        int tamanho;

    public:
        ListaEncadeada();
        ~ListaEncadeada();

        // Insere o elemento e na última posição
        bool push_back(int e);
        // Insere o elemento e na primeira posição
        bool push_front(int e);
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
        void print();

    private:
	    // Dobrar a capacidade quando não houver mais espaço
	    // Reduzir a capacidade pela metade quando for inferior a 25% de ocupação
        void gerenciaCapacidade();        
};

ListaEncadeada::ListaEncadeada(){
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->tamanho = 0;
}
ListaEncadeada::~ListaEncadeada(){}
    
No::No(){}

No::No(int e){
    this->dado = e;
}

No::No(int e, No* prox){
    this->dado = e;
    this->prox = prox;
}

bool ListaEncadeada::push_back(int e){
    No* n = new No(e, nullptr);
    if(this->primeiro == nullptr){
        primeiro = n;
    }
    if(this->ultimo != nullptr){
        ultimo->prox = n;
    }
    ultimo = n;
    n->dado = e;
    tamanho++;
    
    return true;
}

bool ListaEncadeada::push_front(int e){
    No* n = new No(e);
    n->prox = primeiro;
    primeiro = n;
    tamanho++;
    return true;
}

bool ListaEncadeada::insert(int pos, int e){
    No* n = new No(e);
    No* temp;
    for (int i = 0; i < pos; i++)
    {
        temp->prox = 
    }
    
}

void ListaEncadeada::print(){
    No* temp = primeiro;
    cout << "[";
    while(temp != nullptr){
        cout << temp->dado;
        temp = temp->prox;
        if(temp != nullptr) cout << ",";
    }
    cout << "]";
}
