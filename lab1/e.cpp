#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> foo(5);
    deque <int> foo1(5);
    for(int i=0;i<5;i++){
        cin>>foo[i];
    }for(int i=0;i<5;i++){
        cin>>foo1[i];
    }
    int cnt=0;
    while(!foo.empty() && !foo1.empty() && cnt<1000000){
        int a = foo.front();
        int b = foo1.front();
        
        if(a==0 && b==9){
            foo.push_back(a);
            foo.push_back(b);
            foo.pop_front();
            foo1.pop_front();
        }else if(a==9 && b==0){
            foo1.push_back(a);
            foo1.push_back(b);
            foo.pop_front();
            foo1.pop_front();
        }else if(a<b){
            foo1.push_back(a);
            foo1.push_back(b);
            foo.pop_front();
            foo1.pop_front();
        }else if(a>b){
            foo.push_back(a);
            foo.push_back(b);
            foo.pop_front();
            foo1.pop_front();
        }
        cnt++;
    }
    if(!foo1.empty()){
        cout<<"Nursik "<<cnt<<endl;
    }else if(!foo.empty()){
        cout<<"Boris "<<cnt<<endl;
    }else{
        cout<<"blin nichya\n";
    }
    
}