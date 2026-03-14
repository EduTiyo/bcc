#include <iostream>

using namespace std;

unsigned int somaDigitos(unsigned int n){
    unsigned int soma = 0;
    soma = n%10;
    if(n == 0) return soma;
    return soma + somaDigitos(n/10);
}

bool palindromo(char* s, int i, int f){
    if(i >= f) return true;
    if (s[i] == s[f]) return palindromo(s, i+1, f-1);
    return false;
}

int main(){

    // cout << somaDigitos(1234) << endl;
    char s[] = "ana";
    cout << palindromo(s, 0, 2) << endl;

    return 0;
}