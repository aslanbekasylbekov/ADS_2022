//example for Stacks
#include <bits/stdc++.h>
using namespace std;
int main(){
    stack <int> foo;
    string command;
    while(cin>>command){
        if(command == "push"){
            int x;
            cin>>x;
            foo.push(x);
            cout<<"ok\n";
        }else if(command=="size"){
            cout<<foo.size()<<endl;
        }else if(command=="clear"){
            while(!foo.empty()) foo.pop();
            cout<<"ok\n";
        }else if(command=="back"){
            if(foo.size()==0){
                cout<<"error\n";
            }else{
                cout<<foo.top()<<endl;
            }
        }else if(command=="exit"){
            cout<<"bye\n";
            break;
        }else if(command=="pop"){
            if(foo.size()==0){
                cout<<"error\n";
            }else{
                cout<<foo.top()<<endl;
                foo.pop();
            }
        }
    }
}