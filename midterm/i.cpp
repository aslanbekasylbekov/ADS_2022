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
    for(int i=0;i<n;i++){
        long long x; cin>>x;
        to_binary(x);
        string t = to_binary(x);
        stack <char> foo;
        for(int j=0;j<t.size();j++){
            if(foo.empty()){
                foo.push(t[j]);
            } else if(t[j] == '0' and foo.top() == '1'){
                foo.pop();
            } else foo.push(t[j]);
        }
        if(foo.empty()){
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }

    return 0;
}