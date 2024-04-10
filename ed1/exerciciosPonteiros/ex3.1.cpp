#include <iostream>
using namespace std;

int main(){

    int v1[3] = {1,2,3};
    int* p1 = v1;
    
    int v2[3] = {4,5,6};
    int*p2 = v2;

    int* m[2] = {v1, v2};
    int** pm = m;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << *(*(m+i)+j) << " ";
        }
        
    }
    

    return 0;
}