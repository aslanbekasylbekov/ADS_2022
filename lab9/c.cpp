#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> prefixFunction(string s){
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
    string str="";
    vector <long long> pi=prefixFunction(s);
    for(int i=0;i<s.size();i++){
        if(pi[i]==t.size()){
            return (i-2*t.size());
        }
    }
    return -1;
}

int main(){
    string s,t;
    cin>>s>>t;
    if(kmp(s,t)!=-1){
        cout<<s.size();
        return 0;
    }
    s+=s;
    if(kmp(s,t)!=-1){
        cout<<t.size()-kmp(s,t);
        return 0;
    }
    cout<<-1;
}