//example for Deque
#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> foo;
    string command;
    while(cin>>command){
        if(command == "push_back"){
            int x;
            cin>>x;
            foo.push_back(x);
            cout<<"ok\n";
        }else if(command=="size"){
            cout<<foo.size()<<endl;
        }else if(command=="clear"){
            while(!foo.empty()) foo.clear();
            cout<<"ok\n";
        }else if(command=="front"){
            if(foo.size()==0){
                cout<<"error\n";
            }else{
                cout<<foo.front()<<endl;
            }
        }else if(command=="exit"){
            cout<<"bye\n";
            break;
        }else if(command=="back"){
            if(foo.size()==0){
                cout<<"error\n";
            }else{
                cout<<foo.back()<<endl;
            }
        }else if(command == "push_front"){
            int x;
            cin>>x;
            foo.push_front(x);
            cout<<"ok\n";
        }else if(command == "pop_back"){
            if(foo.size()==0){
                cout<<"error\n";
            }else{
                cout<<foo.back()<<endl;
                foo.pop_back();
            }           
        }else if(command == "pop_front"){
            if(foo.size()==0){
                cout<<"error\n";
            }else{
                cout<<foo.front()<<endl;
                foo.pop_front();
            } 
        }        
    }
}