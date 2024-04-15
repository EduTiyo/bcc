#include <iostream>

using namespace std;

class Motor{
    public:
        void start(){
            cout << "motor iniciado" << endl;
        }
};

class Carro{
    private:
        Motor motor;
    public:
        Motor getEngine(){
            return motor;
        }

};

int main(){

    Carro carro;
    carro.getEngine().start();

    return 0;
}