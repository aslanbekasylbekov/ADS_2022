#include <bits/stdc++.h>
using namespace std;
int main(){
    stack <char> foo;
    string s; cin>>s;
    bool ok = true;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{'){
            foo.push(s[i]);
        }else if(s[i]==')'||s[i]==']'||s[i]=='}'){
            if(!foo.empty()){
                if((s[i]==')' and foo.top()=='(')||(s[i]==']' and foo.top()=='[')||(s[i]=='}' and foo.top()=='{')){
                    foo.pop();
                }else{
                    ok=false;
                }
            }                    
        }
    }
    if(!foo.empty() || ok==false){
        cout<<"no";
    }else{
        cout<<"yes";
    }
    return 0; 
}