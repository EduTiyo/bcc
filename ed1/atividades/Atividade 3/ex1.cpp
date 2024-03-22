#include <iostream>
#include <string>
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

int main(){
    
    string str = {"o rato roeu a roupa do rei de roma"};
    int tam = str.size();


    int pos = stringFindFirst(str, 't');
    cout << pos << endl;

    bool check = isLetter('s');
    cout << check << endl;

    bool check = checkName("eduardo tiyo");
    cout << check << endl;

    int* vector = createArray(5, false);
    
    for (int i = 0; i < 5; i++)
    {
        cout << vector[i] << ' ';
    }
        printf("\n");
    
    
    delete vector;

    return 0;
}