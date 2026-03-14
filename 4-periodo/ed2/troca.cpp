#include <iostream>
using namespace std;

template <typename T>
void troca(T&a, T&b){
    T temp = a;
    a=b;
    b=temp;
}

int main(){

    float a = 1.1;
    float b = 4.3;
    troca(a,b);
    cout << a << " " << b << endl;

    return 0;
    
}