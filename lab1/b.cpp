#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    stack <int> foo;
    queue <int> q;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        q.push(x);
    }
    while(!q.empty()){
        if(foo.empty()){
            cout<<"-1 ";
            foo.push(q.front());
            q.pop();
        }else if(foo.top()<=q.front()){
            cout<<foo.top()<<" ";
            foo.push(q.front());
            q.pop();
        }else{
            foo.pop();
        }
    }
}