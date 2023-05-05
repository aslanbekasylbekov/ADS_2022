#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 9;
long long P = 31;

long long getHash(string s){
    long long hash = 0;
    long long curP = 1;
    for(int i=0;i<s.size();i++){
        long long curHash = (s[i] - 'a' + 1) * curP % MOD;
        hash = (hash + curHash) % MOD;
        curP = (curP * P) % MOD;
    }
    return hash;
}
vector <long long> getPrefixHashes(string s){
    vector <long long> hashes(s.size());
    long long curP=1;
    for(int i=0;i<s.size();i++){
        hashes[i] = (s[i]-'a'+1) * curP % MOD;
        if(i != 0){
            hashes[i] = (hashes[i] + hashes[i-1]) % MOD;
        }
        curP = (curP * P) % MOD;
    }
    return hashes;
} 

void rabinKarp(string s,pair<string,int> &patterns,int &mx){
    long long smallHash = getHash(patterns.first);
    vector <long long> hashes = getPrefixHashes(s);
    for(int i=0;i<s.size()-patterns.first.size()+1;i++){
        long long hashDiff = hashes[i + patterns.first.size()-1];
        if(i!=0) hashDiff -=hashes[i-1];
        if(hashDiff<0) hashDiff += MOD;
        if(i != 0) smallHash=(smallHash * P) % MOD;
        if(smallHash==hashDiff){
            patterns.second++;
            mx=max(mx,(patterns.second));
        }
    }
}

int main(){
    while(true){
        int n; cin>>n;
        if(n==0) break;
        pair<string,int> pattern[n];
        for(int i=0;i<n;i++){
            cin>>pattern[i].first;
        }
        int mx=0;
        string s; cin>>s;
        for(int i=0;i<n;i++){
            rabinKarp(s,pattern[i],mx);
        }  
        cout<<mx<<" "<<endl;
        for(int i=0;i<n;i++){
            if(pattern[i].second == mx){
                cout<<pattern[i].first<<endl;
            }
        }
    }
}