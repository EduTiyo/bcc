#include <iostream>
#include "listaDupla.hpp"

int main(){

    ListaDupla* l1 = new ListaDupla();
    l1->push_front(0);
    l1->push_back(1);
    l1->push_back(2);
    l1->push_back(3);
    // l1->pop_back(); pop_back funcionando
    // l1->pop_front(); pop_front funcionando
    // l1->clear(); clear funcionando
    // l1->insert(2,4); insert funcionando
    l1->print();
    cout << l1->size() << endl;
    // cout << l1->printTamanho() << endl;

    return 0;
}