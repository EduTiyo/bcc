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
    // l1.pop_front();
    // l1.pop_back();
    // l1.erase(4);
    // cout << l1.front() << endl;
    // cout << l1.back() << endl;
    // cout << l1.at(3) << endl;
    // l1.clear();
    // cout << l1.empty() << endl;
    // cout << l1.size() << endl;
    l1.replace(3, 10);
    l1.print();

    return 0;
}