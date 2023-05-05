#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <char> foo;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(foo.empty()){
            foo.push_back(s[i]);
        }else if(s[i]==foo.back()){
            foo.pop_back();
        }else{
            foo.push_back(s[i]);
        }
    }
    if(foo.empty()){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}