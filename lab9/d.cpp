#include <bits/stdc++.h>
using namespace std;

int prefixFunction(string s){
    vector <long long> pi(s.size());
    for(int i=1;i<s.size();i++){
        long long j=pi[i-1];
        while(j>0 && s[j]!=s[i]){
            j=pi[j-1];
        }
        if(s[j]==s[i]){
            pi[i]=j+1;
        }
        else{
            pi[i]=0;
        }
    }
    cout << s << endl;
    for(auto i : pi) cout << i << " ";
    cout << endl << endl;
    return pi[pi.size()-1];
}

int main() {
    string s;
    cin >> s;
    s[0] += 32;
    int mx = 1;
    int n;
    cin >> n;
    vector <string> v;
    for(int i=0;i<n;i++){
        string t; cin >> t;
        string x = t; 
        x[0] = (x[0] + 32);
        x = x + '#' + s;
        int last = prefixFunction(x);
        if(mx == last) v.push_back(t);
        if(mx < last){
            v.clear();
            v.push_back(t);
            mx = last;
        }
    }
    cout << v.size() << endl;
    for(auto i : v){
        cout << i << endl;
    }
    return 0;
}