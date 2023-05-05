#include <bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    string d; cin>>d;
    stack<string> foo;
    stack<string> foo1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='#'&& !foo.empty()){
            foo.pop();
        }else if(s[i]!='#'){
            foo.push(s[i]);
        }
    }
    for(int i=0;i<d.size();i++){
        if(d[i]=='#'&&!foo1.empty()){
            foo1.pop();
        }else if(d[i]!='#'){
            foo1.push(d[i]);
        }
    }
    if(foo.size()!=foo1.size()){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
    }
}   