#include <iostream>
#include <vector>
using namespace std;

vector<long long> prefixFunction(string s){
    vector <long long> pi(s.size());
    for(long long i=1;i<s.size();i++){
        long long j=pi[i-1];
        while(j>0 && s[j] != s[i]){
            j=pi[j-1];
        }
        if(s[j]==s[i]){
            pi[i]=j+1;
        }
        else{
            pi[i]=0;
        }
    }
    return pi;
}

long long kmp(string s,string t){
    s = t+'#'+s;
    vector <long long> res;
    vector <long long> pi=prefixFunction(s);
    for(int i=0;i<s.size();i++){
        if(pi[i]==t.size()){
            return (i-2*t.size());
        }
    }
    return -1;
}

int main(){
    string s;
    cin>>s;
    string temp = "";
    vector <long long> ans;  
    vector <long long> pi = prefixFunction(s);
    for(int i=0;i<pi.size();i++){
        ans.push_back(pi[i]);
    }
    cout<<s.size()-ans[s.size()-1];
}