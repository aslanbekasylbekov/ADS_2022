#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e+20;
long long P = 31;

long long getHash(string s){
    int size = s.size();
    unordered_map<long long,bool> mapik;
    for(int i=0;i<size;i++){
        long long hashes = 0;
        long long curP = 1;
        for(int j=i;j<size;j++){
            long long curHash = ((s[j]-'a'+1)*curP) % MOD;
            hashes = (hashes+curHash) % MOD;
            curP=(curP*P) % MOD;
            if(mapik[hashes]==false) mapik[hashes] = true;
        }
    }
    return mapik.size();
}
int main(){
    string s; cin>>s;
    cout<<getHash(s);
}