#include <bits/stdc++.h>
using namespace std;
int main(){
    stack <char> foo;
    stack <char> foo1;
    string s; cin>>s;
    string t; cin>>t;
    for(int i=0;i<s.size();i++){
        if(s[i]=='#'){
            foo.pop();
        }else{
            foo.push(s[i]);
        }
    }for(int i=0;i<t.size();i++){
        if(t[i]=='#'){
            foo1.pop();
        }else{
            foo1.push(t[i]);
        }
    }
    if(foo.size()==foo1.size()){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}