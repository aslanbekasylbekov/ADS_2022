#include <iostream>
#include <vector>
using namespace std;

vector <int> prefixFunction(string s){
    vector <int> pi(s.size());
    for(int i=1;i<s.size();i++){
        int j=pi[i-1];
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
    vector <int> res;
    vector <int> pi=prefixFunction(s);
    for(int i=0;i<s.size();i++){
        if(pi[i]==t.size()){
            return (i-2*t.size());
        }
    }
    return -1;
}

int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        int k; cin>>k;
        vector <int> pi=prefixFunction(s);
        vector <int> ans;
        for(int i=0;i<pi.size();i++){
            ans.push_back(pi[i]);
        }
        cout<<(s.size() - ans[s.size()-1]) * (k-1) + s.size()<<endl;
    }
    
    
}