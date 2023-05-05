#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> foo;
    char s;
    while(cin>>s){       
        if('+'==s){
            int n; cin>>n;
            foo.push_front(n);
        }else if('-'==s){
            int n; cin>>n;
            foo.push_back(n);
        }else if('*'==s){
            if(!foo.empty()){
                cout<<(foo.front()+foo.back())<<endl;
                foo.pop_front();
                if(!foo.empty()){
                    foo.pop_back();
                }                           
            }else{
                cout<<"error\n";
            }
            
        }else if('!'==s){
            break;
        }
    }
}