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
        void start(){
            motor.start();
        }

};

int main(){

    Carro carro;
    carro.start();

    return 0;
}