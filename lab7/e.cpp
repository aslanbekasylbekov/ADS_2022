#include <bits/stdc++.h>
using namespace std;
struct row{
    int sum;
    vector<int>foo;
    row(){
        sum = 0;
    }
    void append(int x){
        sum += x;
        foo.push_back(x);
    }
    bool greater(row * other){
        if(sum>other->sum) return true;
        if(sum==other->sum){
            for(int i=0;i<foo.size();i++){
                if(foo[i] != other->foo[i]){
                    return foo[i] < other->foo[i];
                }
            }
            return false;
        }
        return false;
    }
    void print(){
        for(int i=0;i<foo.size();i++){
            cout<<foo[i]<<" ";
        }
        cout<<endl;
    }
};
void mergeOne(row * a, int l1, int r1, int l2, int r2){
    int n1 = r1 - l1 + 1;
    row L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }
    int n2 = r2 - l2 + 1;
    row R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }
    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 && i2 < n2){
        if(L[i1].greater(&R[i2])){
            a[i++] = L[i1++];
        }else {
            a[i++] = R[i2++];
        }
    }    
    while(i1 < n1){
        a[i++] = L[i1++];
    }  
    while(i2 < n2){
        a[i++] = R[i2++];
    }
}
void mergeSort(row * a, int l, int r){
    if(l < r){
        int m = (l+r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        mergeOne(a, l, m , m + 1, r);
    }
}
int main(){
    int n, m, x;
    cin >> n >> m;
    row rows[n];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> x;
            rows[i].append(x);
        }
    }
    mergeSort(rows, 0, n - 1);
    for(int i=0;i<n;i++){
        rows[i].print();
    }
    return 0;
}