#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int stringFindFirst(string s, char c){
    int pos = 0;
    for (char chr : s)
    {
        if(c == chr) return pos;
        pos++;
    }
    return -1;
}

bool isLetter(char c){
    string alphabet = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
    for (int i = 0; i < alphabet.size(); i++)
    {
        if(c == alphabet[i]) return true;
    }
    return false;
    
}

int* createArray(int n, bool asc){
    int* v = new int(n);
    if(asc){
        for (int i = 0; i < n; i++)
        {
            v[i] = i+1;
        }
    }
    else{
        for(int i = 0, num = n; i < n; i++, num--){
            v[i] = num;
        }
    }
    return v;
}

bool checkName(string str){
    
    if(str[0] == ' ' || str[str.size()-1] == ' ') return false;
    if(!isLetter(str[0])) return false;
    for (int i = 1; i < str.size(); i++)
    {
        if(!isLetter(str[i]) && str[i] != ' ') return false;
        if(str[i] == ' ' && str[i-1] == ' ') return false;
    }
    return true;
    
}

int* arrayConcat(int* v1, int n1, int* v2, int n2){
    int max = n1+n2;
    int* v3 = (int*)malloc(sizeof(int)*max);
    int i = 0;
    for (i; i < n1; i++)
    {
        v3[i] = v1[i];
    }
    cout << i << endl;

    for (int j = 0; j < n2; j++)
    {
        v3[i] = v2[j];
        i++;
    }
    return v3;
    
}

int* arrayMerge(int* v1, int n1, int* v2, int n2){
    int* v3 = (int*)malloc(sizeof(int)*(n1+n2));
    int i = 0, j = 0, z = 0;
    while(i < n1 && j < n2){
        if(v1[i] <= v2[j]){
            v3[z] = v1[i];
            i++, z++;
            continue;
        }
        else{
            v3[z] = v2[j];
            j++, z++;
            continue;
        }
    }
    while (i < n1){
        v3[z] = v1[i];
        z++, i++;
    }
    
    
    while(j < n2){
        v3[z] = v2[j];
        j++, z++;
    }
    
    return v3;
}

int main(){
    
    // string str = {"o rato roeu a roupa do rei de roma"};
    // int tam = str.size();


    // int pos = stringFindFirst(str, 't');
    // cout << pos << endl;

    // bool check = isLetter('s');
    // cout << check << endl;

    // bool check = checkName("eduardo tiyo");
    // cout << check << endl;

    // int* vector = createArray(5, false);
    // int v1[5] = {1,2,3,4,5};
    // int v2[4] = {6,7,8,9};
    // int* vector = arrayConcat(v1, 5, v2, 4);
    
    // int v1[5] = {1,2,4,6,8};
    // int v2[4] = {3,5,9,20};
    // int* vector = arrayMerge(v1,5,v2,4);
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << vector[i] << ' ';
    // }
    //     printf("\n");
    
    vector<int> vec = {1,2,3};
    vec.push_back(10);

    for(int num : vec){
        cout << num << " ";
    }
    // delete vector;
    // free(vector);
    

    return 0;
}