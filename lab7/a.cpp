#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string s1,string s2){
    if(s1.size()<=s2.size()) return true;
    if(s1.size()==s2.size() && s1<=s2) return true;
    return false;
}
void merge(vector <string>& v, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector <string> L(n1);
    vector <string> R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = v[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = v[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i < n1 && j < n2){
        if(cmp(L[i],R[j])){
            v[k] = L[i];
            i++;
        }
        else{
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        v[k++] = L[i++];
    }
    while(j < n2){
        v[k++] = R[j++];
    }
}

void mergeSort(vector <string>& v, int l, int r){
    if(l<r){
        int m = (l+r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){   
        string s;
        vector <string> foo;
        getline(cin >> ws, s);
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' '){
                foo.push_back(res);
                res = "";
            }else{
                res+=s[i];
            }
        }
        foo.push_back(res);
        mergeSort(foo,0,foo.size() - 1);
        for(auto i:foo){
            cout<<i<<" ";
        }
        cout << endl;
    }
}