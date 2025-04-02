#include <iostream>
#include <string>
using namespace std;

void troca_por_valor(int a , int b){
    int temp = a;
    a = b;
    b = temp;
}

void troca_por_ponteiro(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void troca_por_referencia(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){

    int a = 10;
    int b = 20;    
    // troca_por_valor(a,b);
    // cout << "troca por valor: " << "x: " << a << " b: " << b << endl;
    // troca_por_ponteiro(&a, &b);
    // cout << "troca por ponteiro: " << "x: " << a << " b: " << b << endl;
    troca_por_referencia(a,b);
    cout << "troca por referencia: " << "x: " << a << " b: " << b << endl;


    return 0;
}