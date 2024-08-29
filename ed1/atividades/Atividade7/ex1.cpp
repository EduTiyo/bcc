#include <iostream>
#include <string>

using namespace std;

int mdc(int x, int y){
    int _mdc = 1;
    if(x%y==0) return y;
    else if(x < y) return mdc(y,x);
    else return mdc(y, x%y);
    return 0;
}

bool buscaSequencial(int elemento, int* v, int tam){
    if(tam == 0) return false;
    if(elemento == v[tam-1]) return true;
    return buscaSequencial(elemento, v, tam-1);
    
}

bool buscaBinariaIterativa(int elemento, int* v, int tam){
    int esquerda = 0;
    int direita = tam-1;
    
    while(esquerda <= direita){
        int meio = esquerda + (direita-esquerda)/2;
        if(elemento == v[meio]) return true;
        if(v[meio] < elemento) esquerda = meio+1;
        else direita = meio-1;
    }
    return false;
}

bool buscaBinariaRecursivaAux(int elemento, int* v, int esquerda, int direita){
    if(esquerda > direita) return false;
    int meio = esquerda + (direita-esquerda)/2;
    if(v[meio]==elemento) return true;
    if(v[meio] > elemento) return buscaBinariaRecursivaAux(elemento, v, esquerda, meio-1);
    return buscaBinariaRecursivaAux(elemento, v, meio+1, direita);
}

bool buscaBinariaRecursiva(int elemento, int* v, int tam){
    return buscaBinariaRecursivaAux(elemento, v, 0, tam-1);
}


void print(int* v , int tam){
    for (int i = 0; i < tam; i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main() {

    // cout << mdc(100, 50) << endl;
    // int v[9] = {1,2,3,4,12,1,2,3,4};
    // cout << buscaSequencial(120, v, 9) << endl;;
    int v[10] = {2,5,6,10,12,13,15,16,20,40};
    // cout << buscaBinariaIterativa(11, v, 10) << endl;
    cout << buscaBinariaRecursiva(2, v, 10) << endl;
    // print(v, 10);

    
    return 0;
}