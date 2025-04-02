#include <iostream>
using namespace std;

typedef struct{
    int codigo;
    char descricao[12];
    float preco;

} Produto;

int main(){
    
    Produto prod = {10, "Teclado", 98.5};
    Produto* p = &prod;
    int* pi = &prod.codigo;
    char* pc = prod.descricao;
    float* pf = &prod.preco;

    prod.codigo = 20;
    cout << prod.codigo << ", ";
    (*p).codigo = 30;
    cout << prod.codigo << ", ";
    p->codigo = 40;
    cout << prod.codigo << ", ";
    *pi = 50;
    cout << prod.codigo << endl;

    prod.preco = 100.1;
    cout << prod.preco << ", ";
    (*p).preco = 100.2;
    cout << prod.preco << ", ";
    p->preco = 100.3;
    cout << prod.preco << ", ";
    *pf = 100.4;
    cout << prod.preco << endl;
    

    return 0;
}