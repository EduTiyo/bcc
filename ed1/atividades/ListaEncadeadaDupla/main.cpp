#include <iostream>
#include "listaDupla.hpp"

int main(){

    ListaDupla* l1 = new ListaDupla();
    l1->push_front(0);
    l1->push_back(1);
    l1->push_back(2);
    l1->push_back(3);
    l1->pop_back();
    l1->pop_back();
    l1->pop_back();
    l1->pop_back();
    
    l1->print();
    // cout << l1->printTamanho() << endl;

    return 0;
}