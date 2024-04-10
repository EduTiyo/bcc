#include <iostream>
using namespace std;

int main(){

    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    int* v[4] = {&a, &b, &c, &d};
    int** p = v;

    for (int i = 0; i < 4; i++)
    {
        cout << **(p+i) << " ";
    }
    

    return 0;
}