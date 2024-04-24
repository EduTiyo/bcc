#include <iostream>
#include "Lista.h"

using namespace std;

int main(){

    ListaEncadeada l1;
    No* n1 = new No(1);
    No* n2 = new No(2);
    No* n3 = new No(3, nullptr);
    l1.setPrimeiro(n1);
    l1.push_back(n2);
    l1.push_back(n3);
    l1.print(n1);

    return 0;
}