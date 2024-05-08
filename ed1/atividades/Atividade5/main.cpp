#include "vetor.h"
#include <string>
#include <iostream>

using namespace std;

int main(){

    Vetor v1;
    v1.push_back(3);
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(30);
    v1.push_back(20);
    v1.push_back(20);
    v1.push_back(20);
    // v1.push_front(100);
    // v1.insert(2, 31);
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    // v1.pop_back();
    // v1.pop_front();
    // v1.erase(2);
    // cout << v1.front() << endl;
    // cout << v1.back() << endl;
    // cout << v1.at(2);
    // v1.clear();
    // cout << v1.empty();
    // cout << v1.size();
    // v1.replace(1, 29);

    v1.print();

    return 0;
}