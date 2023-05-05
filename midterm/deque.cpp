#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
    int n; cin>>n;
    deque<int> foo;
    
    for(int i=0;i<n;i++){
        string s; cin>>s;
        if(s=="push_back"){
            int t; cin>>t;
            foo.push_back(t);
        }
        if(s=="push_front"){
            int t; cin>>t;
            foo.push_front(t);
        }
        if(s=="front"){
            if(foo.empty()){
                cout<<";("<<endl;
            }
            else{
                cout<<foo.front()<<endl;
                foo.pop_front();
            }   
        }
        if(s=="back"){
            if(foo.empty()){
                cout<<";("<<endl;
            }
            else{
                cout<<foo.back()<<endl;
                foo.pop_back();
            } 
        }
        if(s=="reverse"){
            reverse(foo.begin(),foo.end());
        }
    }
}