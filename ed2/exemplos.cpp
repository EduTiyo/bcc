#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <utility>
#include <algorithm>

using namespace std;

unordered_map<int, int> contarFrequencia(vector<int>& array){
    unordered_map<int, int> frequencia;
    for(int x : array){
        frequencia[x]++;
    }
    return frequencia;
}

int primeiroUnico(vector<int>& array){
    unordered_map<int, int> frequencia = contarFrequencia(array);
    int i = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if(frequencia[array[i]] == 1) return i;
    }    
    return -1;
}

pair<int,int> twoSum(vector<int>& array, int k){
    unordered_set<int> complementos;
    for(int num : array){
        int complemento = k - num;

        if(complementos.find(complemento) != complementos.end()) return make_pair(complemento, num);
        complementos.insert(num);
    }
    return make_pair(-1,-1);
}

bool temDuplicatas(vector<int>& array){
    unordered_set<int> numeros;
    for(int num : array){
        if(numeros.find(num) != numeros.end()) return true;
        numeros.insert(num);
    }
    return false;
}

vector<int> semDuplicatas(vector<int>& array){
    unordered_set<int> numeros;
    vector<int> newArray;
    for(int num : array){
        if(numeros.find(num) == numeros.end()){
            numeros.insert(num);
            newArray.push_back(num);
        }
    }
    return newArray;
}

vector<vector<string>> agruparAnagramas(vector<string>& palavras){
    unordered_map<string, vector<string>> mapaAnagramas;
    for(const string& palavra : palavras){
        string chave = palavra;
        sort(chave.begin(), chave.end());
        mapaAnagramas[chave].push_back(palavra);
    }
    vector<vector<string>> resultado;
    for(auto& [chave, grupo] : mapaAnagramas){
        resultado.push_back(grupo);
    }
    return resultado;
}

int maiorSequenciaConsecutiva(vector<int>& array){
    unordered_set<int> numeros(array.begin(), array.end());
    int maiorSequencia = 0;

    for(int num : array){
        if(numeros.find(num-1) == numeros.end()){
            int atual = num;
            int sequenciaAtual = 1;

            while(numeros.find(atual+1) != numeros.end()){
                atual++;
                sequenciaAtual++;
            }
            maiorSequencia = max(sequenciaAtual, maiorSequencia);
        }
    }
    
    return maiorSequencia;
}

bool temSubVetorSomaZero(vector<int>& array){
    unordered_set<int> somas;
    somas.insert(0);

    for(auto num : array){
        unordered_set<int> somasNovas;
        if(somas.find(-num) != somas.end()) return 1;
        for(int soma : somas){
            somasNovas.insert(soma+num);
        }
        somas.insert(somasNovas.begin(), somasNovas.end());   
    }
    return 0;
}

bool temSubVetorSomaK(vector<int>& array, int k){
    unordered_set<int> somas;
    somas.insert(0);

    for(auto num : array){
        unordered_set<int> somasNovas;
        if(somas.find(k) != somas.end()) return 1;
        for(int soma : somas){
            somasNovas.insert(soma+num);
        }
        somas.insert(somasNovas.begin(), somasNovas.end());   
    }
    return 0;
}

bool saoIguais(vector<int>& arr1, vector<int>& arr2){
    unordered_set<int> nums1(arr1.begin(), arr1.end());
    unordered_set<int> nums2(arr2.begin(), arr2.end());

    // if(nums1.size() != nums2.size()) return false;

    for(auto num : nums1){
        if(nums2.find(num) == nums2.end()) return false;
    }
    return true;
}

vector<int> uniao(vector<int>& v1, vector<int>& v2){
    unordered_set<int> numsUniao(v1.begin(), v1.end());

    for(int num : v2){
        if(numsUniao.count(num) == 0) numsUniao.insert(num);
    }

    vector<int> resultado;
    
    for(int nums : numsUniao){
        resultado.push_back(nums);
    }
    return resultado;
}

vector<int> intersecao(vector<int>& v1, vector<int>& v2){
    unordered_set<int> nums(v1.begin(), v1.end());
    vector<int> resultado;
    for(int x : v2){
        if(nums.count(x) > 0) resultado.push_back(x);
    }
    return resultado;
}

vector<int> diferenca(vector<int>& v1, vector<int>& v2){
    unordered_set<int> nums1(v1.begin(), v1.end());
    unordered_set<int> nums2(v2.begin(), v2.end());
    vector<int> resultado;

    for(int x : nums2){
        if(nums1.count(x) == 0) resultado.push_back(x);
    }
    for(int y : nums1){
        if(nums2.count(y) == 0) resultado.push_back(y);
    }
    return resultado;
}

bool isSubconjunto(vector<int>& v1, vector<int>& v2){
    unordered_set<int> nums1(v1.begin(), v1.end());
    unordered_set<int> nums2(v2.begin(), v2.end());

    for(int x : nums2){
        if(nums1.count(x) == 0) return false;
    }
    return true;
}

bool isDisjuntos(vector<int>& v1, vector<int>& v2){
    unordered_set<int> nums1(v1.begin(), v1.end());
    unordered_set<int> nums2(v2.begin(), v2.end());

    for(int x : nums2){
        if(nums1.count(x) > 0) return false;
    }
    return true;
}

int elemMajoritario(vector<int>& v){
    unordered_map<int, int> frequencia;
    
    for(int x : v){
        frequencia[x]++;
    }
    for(auto y : frequencia){
        if(y.second > v.size()/2) return y.first;
    }
    return -1;
    
}

int main() {
    vector<int> arr = {1,2,3,4,4,4,2,2,2,2,2,2,2,2,2,22};
    // std::unordered_map<int, int> resultado = contarFrequencia(arr);

    // Exibe o resultado
    // for (const auto& par : resultado) {
    //     cout << "Numero " << par.first << ": " << par.second << " vezes\n";
    // }

    // cout << primeiroUnico(arr) << endl;
    // pair<int, int> par = twoSum(arr, 5);
    // cout << par.first << " " << par.second << endl;
    // cout << temDuplicatas(arr) << endl;

    // vector<int> newArray = semDuplicatas(arr);
    // for(const auto& i : newArray){
    //     cout << i << " ";
    // }
    // cout << endl;

    // vector<string> palavras = {"ate", "eat", "tea", "bat", "tab", "ana", "naa", "cabelo", "cebola"};
    // auto resultado = agruparAnagramas(palavras);
    // for(const auto& grupo : resultado){
    //     cout << "{ ";
    //     for(const string& palavra : grupo){
    //         cout << palavra << " ";
    //     }
    //     cout << "}" << endl;
    // }
    // cout<<endl;

    vector<int> array = {1, 9, 3, 10, -4, 20, 2};
    vector<int> array2 = {0,12,13,1};
    // cout << maiorSequenciaConsecutiva(array) << endl;
    // cout << temSubVetorSomaK(array, 50) << endl;
    // cout << saoIguais(array, array2) << endl;
    // auto resultado = intersecao(array, array2);
    // cout << "{ ";
    // for (int i = 0; i < resultado.size(); i++)
    // {
    //     cout << resultado[i] << " ";
    // }
    
    // cout << "}" << endl;

    // cout << isDisjuntos(array, array2) << endl;

    cout << elemMajoritario(arr) << endl;

    return 0;
}