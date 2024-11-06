#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int partition(vector<int> &v, int p, int r){
    int x = v[r];
    int i = p-1;
    for (int j = p; j < r; j++)
    {
        if(v[j] < x){
            i++;
            swap(v[j], v[i]);
        }
    }
    swap(v[r], v[i+1]);
    return i+1;
}

void quickSort(vector<int> &v, int p, int r){
    if(p<r){
        int q = partition(v,p,r);
        quickSort(v,p,q-1);
        quickSort(v,q+1, r);
    }
}

int main(){

    vector<int> vet = {5,4,7,1,0,10,9,0,11,3};
    quickSort(vet,0,10);
    
    for (int i = 0; i < vet.size(); i++)
    {
        cout << vet[i] << " ";
    }
    cout << endl;
    return 0;
}