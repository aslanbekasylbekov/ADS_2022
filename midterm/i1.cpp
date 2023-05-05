#include <bits/stdc++.h>
using namespace std;

string to_binary(long long n, string ans=""){
    if(n == 0){
        reverse(ans.begin(), ans.end());
        return ans;
    }
    return to_binary(n/2, ans+=(n%2+'0'));
}
int main(){
    long long n; cin>>n;
    stack <char> foo;
    bool ok=true;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        to_binary(x);
        string t = to_binary(x);
        for(int j=0;j<t.size();j++){
            if(t[j]=='1'){
                foo.push(t[j]);
            } else if(t[j]=='0'){
                if(!foo.empty()){
                    if(t[j]=='0' && foo.top()=='1'){
                        foo.pop();
                    } else ok=false;
                }
            }
            
        }
        if(!foo.empty() || ok==false){
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
        while(!foo.empty()){
            foo.pop();
        }
    }

    // cout << to_binary(n);
}