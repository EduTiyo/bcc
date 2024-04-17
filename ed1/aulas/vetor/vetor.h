#include <string>

using namespace std;

class Vetor{
    private:
        int* array;
        int capacity;
        int size;

    public:
    
        Vetor();
        ~Vetor();

        bool push_back(int e);

        bool push_front(int e);

        bool insert(int pos, int e);

        int pop_back();

        int pop_front();

        int erase(int pos);

        
        int front();

        int back();

        int at(int pos);

        void clear();

        bool empty();

        int size();

        bool replace(int pos, int e);

        void print();
    
    private:

        void gerenciaCapacidade();


};