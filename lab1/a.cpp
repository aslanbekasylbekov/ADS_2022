#include <bits/stdc++.h>
using namespace std;
void func(int n){
    queue <int> foo;
    int a[n];
    for(int i=0;i<n;i++){
        foo.push(i);
    }
    for(int z=1;z<=n;z++){
        for(int j=1;j<=z;j++){
            foo.push(foo.front());
            foo.pop();
        }
        a[foo.front()]=z;
        foo.pop();
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,z; cin>>n;
    for(int i=0,z;i<n;i++){
        cin>>z;
        func(z);
    }
}