#include <iostream>
#include <string>

using namespace std;

class Professor{
    private:
        string name;
    public:
        void ensinar(){cout << "ensinando..." << endl;}
        
};

class ProfMatematica : public Professor{
    public:
        void ensinar(){
            cout << "ensinando Matematica" << endl;
        }
};

class ProfGeografia : public Professor{
    public:
        void ensinar(){
            cout << "ensinando Geografia" << endl;
        }
};

int main(){

    ProfMatematica profMat;
    ProfGeografia profGeo;
    profMat.ensinar();
    profGeo.ensinar();

    return 0;
}