#include <iostream>
#include <vector>
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

bool kmp(string s,string t){
    s = t+'#'+s;
    vector <long long> pi=prefixFunction(s);
    for(int i=0;i<s.size();i++){
        if(pi[i]==t.size()){
            return true;
        }
    }
    return false;
}

int main(){
    string s;
    cin>>s;
    string t; cin>>t;
    int cnt=0;
    string temp="";
    while(temp.size()<t.size()){
        temp+=s;
        cnt++;
    }


    if(kmp(temp, t)){
        cout << cnt++;
    } else{
        temp += s;
        if(kmp(temp, t)){
            cout << cnt + 1;
        } else cout << -1;
    }
    
    return 0;
}