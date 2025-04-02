#include <iostream>
using namespace std;

int main(){

    int v[4]={1,2,3,4};
    int * p = v;
    int * w = v+2;
    int i = 30;
    int * x = &i;

    return 0;
}