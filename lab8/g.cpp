#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 9;
long long P = 31;

long long getHash(string s) {
    long long hash = 0;
    long long curP = 1;
    for(int i=0;i<s.size();i++){
        long long curHash = (s[i] - 'a' + 1) * curP % MOD;
        hash = (hash + curHash) % MOD;
        curP = (curP * P) % MOD;
    }
    return hash;
}

vector<long long> getPrefixHashes(string s) {
    long long curP = 1;
    vector<long long> hashes(s.size());
    for (int i = 0; i < s.size();i++){
        hashes[i] = (s[i] - 'a' + 1) * curP % MOD;
        if(i != 0){
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curP = (curP * P) % MOD;
    }
    return hashes;
}

long long rabinKarp(string s,string t,vector<long long> &hashes) {
    long long cnt=0;
    long long smallHash = getHash(t);   
    for (int i = 0; i < s.size() - t.size() + 1; i ++){
        long long hashDiff = hashes[i + t.size() - 1];
        if(i != 0) hashDiff -= hashes[i - 1];
        if (hashDiff < 0) hashDiff += MOD;
        if (i != 0) smallHash = (smallHash * P) % MOD;
        if (smallHash == hashDiff){
            cnt++;
        }
    }
    return cnt;
}
int main() {
    string s; cin>>s;
    int n; cin>>n;
    vector<long long> hashes = getPrefixHashes(s);
    for(int i=0;i<n;i++){
        int l,r; cin>>l>>r;
        l--;
        string str = "";
        for (int i=l;i<r;i++){
            str+=s[i];
        }
        cout<<rabinKarp(s,str,hashes);
        cout<<endl;
    }
}