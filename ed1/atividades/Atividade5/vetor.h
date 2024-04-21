
#include <string>
#include <iostream>

using namespace std;

class Vetor{

    private:
        int* array;
        int capacity;
        int v_size;

    public:
        Vetor(){
            this->capacity = 1;
            this->v_size = 0;
            this->array = new int(capacity);
        }
        ~Vetor();

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

bool Vetor::push_back(int e){
    gerenciaCapacidade();

    array[v_size] = e;
    v_size++;
    return true;
}

bool Vetor::push_front(int e){
    gerenciaCapacidade();

    for(int i = v_size; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = e;
    v_size++;
    return true;
}

bool Vetor::insert(int pos, int e){
   gerenciaCapacidade();

   for(int i = v_size; i > pos; i--){
        array[i] = array[i-1];
   }
   array[pos] = e;
   v_size++;
   return true;
}

int Vetor::pop_back(){
    int popped = array[v_size-1];
    v_size--;
    gerenciaCapacidade();
    return popped;
}

int Vetor::pop_front(){
    int popped = array[0];
    for(int i = 0; i < v_size; i++){
        array[i] = array[i+1];
    }
    v_size--;
    gerenciaCapacidade();
    return popped;
}

int Vetor::erase(int pos){
    int erased = array[pos];
    for(int i = pos; i < v_size; i++){
        array[i] = array[i+1];
    }
    v_size--;
    gerenciaCapacidade();
    return erased;
}

int Vetor::front(){
    return this->array[0];
}

int Vetor::back(){
    return this->array[v_size-1];
}

int Vetor::at(int pos){
    return this->array[pos];
}

void Vetor::clear(){
    v_size = 0;

}

bool Vetor::empty(){
    if(v_size == 0) return true;
    return false;
}

int Vetor::size(){
    return v_size;
}

bool Vetor::replace(int pos, int e){
    array[pos] = e;
    return true;
}

void Vetor::print(){
    if(v_size == 0){
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for(int i = 0; i < v_size; i++){
        cout << array[i] << ", ";
    }
    cout << "\b\b]"; 
}
void Vetor::gerenciaCapacidade(){
    
    
}