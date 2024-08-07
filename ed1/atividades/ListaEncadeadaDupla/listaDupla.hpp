#include <iostream>
#include <string>

using namespace std;

class No{
    public:
        No* ant;
        int dado;
        No* prox;

        No(){};
        No(int dado){
            this->dado=dado;
        }
        No(No* prox, int dado){
            this->prox=prox;
            this->dado=dado;
        }
        No(No* ant, int dado, No* prox){
            this->ant=ant;
            this->dado=dado;
            this->prox=prox;
        }
        ~No(){};

};

class ListaDupla{
    private:
        int tamanho;
        No* primeiro;
        No* ultimo;
    public:
        ListaDupla(){
            this->tamanho=0;
            this->primeiro=nullptr;
            this->ultimo=nullptr;
        }
        ~ListaDupla(){};

         // Insere o elemento e na última posição
        bool push_back(int e){
            No* novo = new No(e);
            if(this->empty()){
                primeiro = ultimo = novo;
            } else{
                ultimo->prox = novo;
                novo->ant = ultimo;
                ultimo = novo;
            }
            tamanho++;
            return true;
        }
        // Insere o elemento e na primeira posição
        bool push_front(int e){
            if(this->empty()){
                return push_back(e);
            }else{
                No* novo = new No(e);
                novo->prox = primeiro;
                primeiro->ant = novo;
                primeiro = novo;
            }
            tamanho++;
            primeiro->ant = nullptr;
            return true;
        }
        // Insere o elemento e na posição pos
        bool insert(int pos, int e){
            if(pos == 0) return push_front(e);
            else if(pos == tamanho) return push_back(e);
            else if(this->empty()) return push_back(e);
            else{
                No* novo = new No(e);
                int idx = 0;
                No* atual = primeiro;
                while(idx < pos-1){ // 1,2 // 2,2
                    atual = atual->prox;
                    idx++;
                }
                novo->prox = atual->prox;
                novo->ant = atual;
                atual->prox->ant = novo;
                atual->prox = novo;
            }
            tamanho++;
            return true;
            
        }

        // Remove o último elemento
        int pop_back(){
            if (ultimo == nullptr) {
                cout << "a lista esta vazia." << endl;
                return 0;
            }

            No* temp = ultimo;
            if (ultimo->ant != nullptr) {
                ultimo = ultimo->ant;
                ultimo->prox = nullptr;
            } else {
                primeiro = ultimo = nullptr;
            }
            delete temp;
            tamanho--;
            return 0;
        }
        // Remove o primeiro elemento
        int pop_front(){
            if(primeiro == nullptr){
                cout << "a lista está vazia" << endl;
                return 0;
            }
            if(primeiro->prox != nullptr){
                primeiro->prox->ant = nullptr;
                primeiro = primeiro->prox;
            } else{
                primeiro = ultimo = nullptr;
            }
            tamanho--;
            return 0;
        }
        // Remove o elemento da posição pos e retorna o elemento removido
        int erase(int pos){
            if(tamanho==1){
                return this->pop_back();
            }
            else if(pos == tamanho-1){
                return this->pop_back();
            }
            else if(pos == 0){
                return this->pop_front();
            } else {

                No* temp = this->primeiro;
                int i = 0;
                for(i; i < pos; ++i){
                    temp = temp->prox;
                }
                temp->ant->prox = temp->prox;
                temp->prox->ant = temp->ant;
                temp->dado;
                tamanho--;
                return temp->dado;
            }
        }


        // Retorna o primeiro elemento
        int front(){return primeiro->dado;}
        // Retorna o último elemento
        int back(){return ultimo->dado;}
        // Retorna o elemento da posição pos
        int at(int pos);

        // Torna a lista vazia
        void clear(){
            
            while(this->empty()){
                this->pop_back();
            }

            primeiro = nullptr;
            ultimo = nullptr;
            tamanho = 0;

        }

        // Verifica se o vetor está vazio
        bool empty(){
            if(this->ultimo == nullptr && this->primeiro == nullptr){
                return true;
            } else return false;
        }
        // Devolve a quantidade de elementos
        int size(){return this->tamanho;}
        // Substitui o elemento da posição pos pelo elemento e
        bool replace(int pos, int e);

        void print(){

            printf("[");
            No* aux = primeiro;
            while(aux != nullptr){
                if(aux->prox != nullptr){
                    cout << aux->dado << ",";
                }else{
                    cout << aux->dado;
                }
                aux = aux->prox;
            }
            // cout << aux->dado;
            printf("]\n");
        }

        ~ListaDupla(){
            
        }
        
};