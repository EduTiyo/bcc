#include <iostream>
#include <vector>
#include <forward_list>
#include <stack>
#include <queue>

using namespace std;

vector<int> vet_to_vector(int n, int* v){
    vector<int> vec = {};
    for (int i = 0; i < n; i++)
    {
        vec.push_back(v[i]);
    }
    return vec;
}
    
template <typename T>
    void print(const T& a){
        for(const auto& elem : a){
            cout << elem << ' ';
        }
        cout << endl;
    }
    


forward_list<int> vet_to_flist(int n, int*v){
    forward_list<int> fl = {};
    for (int i = 0; i < n; i++)
    {
        fl.push_front(v[i]);
    }
    fl.reverse();
    return fl;
}

stack<int> vet_to_stack(int n, int v[]){
    stack<int> st = {};
    for (int i = n-1; i >= 0; i--)
    {
        st.push(v[i]);
    }
    return st;
}

vector<int> stack_to_vector(stack<int> s){
    vector<int> vec;
    while (!s.empty()) {
        vec.push_back(s.top());
        s.pop();
    }
    return vec;
}

vector<int> list_concat(forward_list<int>& list1, forward_list<int>& list2){
    vector<int> vec = {};
    for(const auto& elem : list1) {
        vec.push_back(elem);
    }
    for(const auto& elem : list2) {
        vec.push_back(elem);
    }
    return vec;
}



int main(){

    int v[5] = {4,3,2,5,1};
    // vector<int> vec = vet_to_vector(5,v);
    // print(vec);
    // forward_list fl = vet_to_flist(5, v);
    // print(fl);
    // stack<int> st = vet_to_stack(5, v);
    // vector<int> vec = stack_to_vector(st);
    forward_list<int> l1 = {1,2,44,14,8,7};
    forward_list<int> l2 = {7,5,0,1,2};
    vector<int> vec = list_concat(l1,l2);
    print(vec);
    
    return 0;
}