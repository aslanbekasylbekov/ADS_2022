#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n; cin>>n;
    stack <int> foo;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        foo.push(k);
    }
    cout<<foo.size()<<endl;
    for(int i=0;i<foo.size();i++){
        cout<<foo.top()<<" ";
        foo.pop();
    }
    cout<<endl;
    
}