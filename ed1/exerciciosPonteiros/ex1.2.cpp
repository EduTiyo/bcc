#include <iostream>
using namespace std;

int main(){
    
    int v[4]={1,2,3,4};
    int* p = v;
    for (int i = 0; i < 4; i++)
    {
        cout << *p << endl;
        p++;
    }
    
        
    return 0;
}