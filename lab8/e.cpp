#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;
long long P = 2;
long long pows[55];
void degree(){
    pows[0] = 1;
    for(int i=1;i<=55;i++){
        pows[i] = pows[i-1] * P;
    }
}

int main(){
    int n; cin>>n;
    degree();
    vector<long long> hash(n);
    for(int i=0;i<n;i++){
        cin>>hash[i];
    }
    for(int i=0;i<n;i++){
        if(i != 0){
            cout<<char((hash[i]-hash[i-1])/pows[i]+97);
        }
        else{
            cout<<char(hash[i]/pows[i]+97);
        }
    }
}