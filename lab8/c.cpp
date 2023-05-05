#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long MOD=1e9+7;
long long P=31;

long long getHash(string s){
    long long hash=0;
    long long curP=1;
    for(int i=0;i<s.size();i++){
        long long curHash=(s[i]-'a'+1) * curP % MOD;
        hash=(hash+curHash) % MOD;
        curP=(curP*P) % MOD;
    }
    return hash;
}
vector <long long> getPrefixHashes(string s){
    vector <long long> hashes(s.size());
    long long curP=1;
    for(int i=0;i<s.size();i++){
        hashes[i]=(s[i]-'a'+1) * curP % MOD;
        if(i != 0){
            hashes[i]=(hashes[i] + hashes[i-1]) % MOD;
        }
        curP = (curP * P) % MOD;
    }
    return hashes;
}
void rabinKarp(string s, string t,vector <long long> &hashes,bool ok[]){
    long long smallHash = getHash(t);
    for(int i=0;i<s.size() - t.size()+1;i++){
        long long hashDiff = hashes[i+t.size()-1];
        if(i!=0) hashDiff -= hashes[i-1];
        if(hashDiff<0) hashDiff += MOD;
        if(i != 0) smallHash = (smallHash*P) % MOD;
        if(smallHash==hashDiff){
            for(int j=i;j<i+t.size();j++){
                ok[j] = true;
            }
        }
    }
}
int main(){
    string s;
    cin>>s;
    int n; cin>>n;
    vector <long long> hashes = getPrefixHashes(s);
    bool ok[s.size()] = {false};
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        rabinKarp(s,x,hashes,ok);
        // for(int j=0;j<s.size();j++){
        //     cout<<ok[j]<<" ";
        // }
        // cout<<endl;
    }
    for(int i=0;i<s.size();i++){
        if(!ok[i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}