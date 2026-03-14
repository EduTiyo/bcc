#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int pos_maior(vector<int>&v, int inicio, int fim){
    int maior = inicio;
    for (inicio; inicio <= fim; inicio++)
    {
        if(v[inicio] > v[maior]){
            maior = inicio;
        }
    }
    return maior;
}

void ordenar(vector<int>& v){
    for (int i = v.size()-1; i >= 0; i--)
    {
        int p = pos_maior(v, 0, i);
        swap(v[p],v[i]);
    }
        
}

int main(){

    vector<int> v = {7,5,1,10,9,4,1,2};
    ordenar(v);
    
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    

    return 0;
}