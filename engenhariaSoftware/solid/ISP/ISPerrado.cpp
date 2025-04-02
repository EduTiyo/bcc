#include <iostream>

using namespace std;

class Animal{
    public:
        void catSound(){
            cout << "miau" << endl;
        }
        void dogSound(){
            cout << "au au" << endl;
        }
};

int main(){

    Animal cat;
    Animal dog;

    cat.catSound();
    dog.dogSound();

    return 0;
}