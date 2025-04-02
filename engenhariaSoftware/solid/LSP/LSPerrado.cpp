#include <iostream>
#include <string>

using namespace std;

class Professor{
    private:
        string name;
    public:
        void ensinar(){cout << "ensinando..." << endl;}
        
};

int main(){

    Professor profMat;
    Professor profGeo;
    profMat.ensinar();
    profGeo.ensinar();

    return 0;
}