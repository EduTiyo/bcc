
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
    No* temp = primeiro;
    for (int i = 0; i < pos-1; i++)
    {
        temp = temp->prox;
    }
    n->prox = temp->prox;
    temp->prox = n;
    tamanho++;
    return true;
}

int ListaEncadeada::pop_back(){
    if(tamanho==0){
        throw out_of_range("lista vazia");
    }
    if (tamanho==1){
        delete primeiro;
        primeiro = ultimo = nullptr;
        tamanho = 0;
        return 0;
    }
    No* temp = primeiro;
    for(int i = 0; i < tamanho-3; i++){
        temp = temp->prox;
    }
    ultimo = temp;
    temp->prox = nullptr;
    tamanho--;
    return 0;    
}

int ListaEncadeada::pop_front(){
    primeiro = primeiro->prox;
    return 0;
}

int ListaEncadeada::erase(int pos){
    if(pos == 0){
        primeiro = primeiro->prox;
        tamanho--;
        return 0;
    }
    
    No* anterior = nullptr;
    No* atual = primeiro;

    for(int i = 0; i < pos; i++){
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = atual->prox;

    if (atual == ultimo){
        ultimo = anterior;
    }
    delete atual;
    tamanho--;

    return 0;
}

int ListaEncadeada::front(){
    return primeiro->dado;
}

int ListaEncadeada::back(){
    return ultimo->dado;
}

int ListaEncadeada::at(int pos){
    No* temp = primeiro;
    for(int i = 0; i < pos; i++){
        temp = temp->prox;
    }
    return temp->dado;
}

void ListaEncadeada::clear(){
    primeiro = nullptr;
    tamanho = 0;
}

bool ListaEncadeada::empty(){
    if(tamanho == 0) return true;
    return false;
}

int ListaEncadeada::size(){
    return tamanho;
}

bool ListaEncadeada::replace(int pos, int e){
    No* temp = primeiro;
    for(int i = 0; i < pos; i++){
        temp = temp->prox;
    }
    temp->dado = e;
    return true;
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
