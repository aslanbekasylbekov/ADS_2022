#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;   cin>>s;
    string temp = "";
    int n=s.size();
    for(int i = 0 ; i<n;i++ ){
        if(s[i]=='z'){
            s[i] = s[0];

        }
        s[i-1] = s[i];
    }

    cout<<s;
    return 0;
}