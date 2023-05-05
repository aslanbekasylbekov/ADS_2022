#include <bits/stdc++.h> 
using namespace std; 

long long MOD = 1e9 + 7; 
long long P = 11; 
 
long long getHash(string s) { 
    long long hash = 0; 
    long long curP = 1; 
    for (int i = 0; i < s.size(); i++) { 
        long long curHash = (s[i] - 'a' +1 ) * curP % MOD; 
        hash = (hash + curHash) % MOD; 
        curP = (curP * P) % MOD; 
    } 
    return hash; 
} 
 
 
int main(){ 
    int n; cin >> n; 
    long long twon = 2 * n; 
    int cnt = 0; 
    string t[twon]; 
    set<string> setik; 
    for(int i = 0; i < twon; i++){ 
        cin >> t[i]; 
        setik.insert(t[i]); 
    }  

    for(int i = 0; i < twon; i++){ 
        string hashOf = to_string(getHash(t[i])); 
        if(setik.find(hashOf) != setik.end()){ 
            cout << "Hash of string \"" << t[i] << "\" is " << hashOf << "\n";  
            cnt ++; 
        } 
        if(cnt == n){ 
            return 0; 
        } 
    } 
}