#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n; cin>>n;
    queue <int> foo;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        foo.push(x);
        if(x>3000){
            int temp = x-3000;
            while(!foo.empty() && foo.front()<temp){
                foo.pop();
            }
        }
        cout<<foo.size()<<" ";
    }
}