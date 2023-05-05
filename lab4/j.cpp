#include <bits/stdc++.h>
using namespace std;
void show(vector <int> &foo,int l,int r){
    int m=(l+r)/2;
    cout<<foo[m]<<" ";
    if(l==r) return;
    show(foo,l,m-1);
    show(foo,m+1,r);
}
int main(){
    int n; cin>>n;
    int sz=pow(2,n)-1;
    vector <int> foo(sz);
    for(int &i:foo){
        cin>>i;
    }
    sort(foo.begin(),foo.end());
    show(foo,0,sz-1);
}