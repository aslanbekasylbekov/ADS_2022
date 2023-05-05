#include <iostream>
#include <vector>
#include <map>
using namespace std;

long long MOD=1e9+7;
long long P=31;
map<int,int> mapik;
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
vector <long long> getPrefiPHashes(string s){
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
int cnt = 0;
void rabinKarp(string s, string t){
    long long smallHash = getHash(t);
    vector <long long> hashes = getPrefiPHashes(s);
    for(int i=0;i<s.size() - t.size()+1;i++){
        long long hashDiff = hashes[i+t.size()-1];
        if(i!=0) hashDiff -= hashes[i-1];
        if(hashDiff<0) hashDiff+=MOD;
        if(i != 0) smallHash = (smallHash*P) % MOD;
        if(smallHash==hashDiff){
            if(mapik.find(i) != mapik.end()){
                cnt++;
            }
            mapik[i]=1;
        }
    }
}
int main(){
    string s,t; cin>>s>>t;
    cout<<getHash(s)<<endl;
    vector <long long> v = getPrefiPHashes(s);
    for(auto i:v){
        cout<<i<<" "<<endl;
    }
    rabinKarp(s,t);
}