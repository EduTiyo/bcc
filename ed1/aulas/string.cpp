#include <iostream>
#include <string>
using namespace std;

int main(){

    string nome1 = "fallen";
    string nome2("yuurih");
    string nome3, nome4;

    nome3 = "art";
    nome4 = nome1 + " professor";

    cout << nome1 << endl;
    cout << nome2 << endl;
    cout << nome3 << endl;
    cout << nome4 << endl;

    cout << nome4.size() << endl;
    cout << nome4.capacity() << endl;
    cout << nome4.max_size() << endl;

    return 0;
}