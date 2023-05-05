#include <bits/stdc++.h>
using namespace std;
int main(){
    long long x; cin>>x;
    long long n; cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==x){
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}    