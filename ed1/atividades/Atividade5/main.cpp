#include "vetor.h"
#include <iostream>
#include <string>

int main(){
    
    Vetor* v1 = new Vetor();
    v1->push_back(10);
    v1->push_back(20);
    v1->push_back(30);
    v1->push_back(40);
    v1->push_back(50);
    v1->push_back(60);
    v1->push_back(70);
    v1->push_back(80);
    v1->push_back(90);
    v1->push_front(100);
    v1->insert(2, 3);
    v1->pop_back();
    v1->pop_front();
    v1->erase(6);
    v1->push_back(123);
    // cout << v1->front() << endl;
    // cout << v1->back() << endl;
    // cout << v1->at(3) << endl;
    // v1->clear();
    // cout << v1->empty() << endl;
    // cout << v1->empty() << endl;
    // cout << v1->size() << endl;
    v1->replace(5, 900);

    v1->print();

    
    return 0;
}