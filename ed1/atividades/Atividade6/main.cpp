#include <iostream>
#include "Lista.h"

using namespace std;

int main(){

    ListaEncadeada l1;

    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(3);
    l1.push_front(0);
    l1.insert(3, 9);
    l1.pop_front();
    l1.pop_back();
    l1.print();

    return 0;
}