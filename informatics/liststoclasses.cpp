#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <string> class_9;
    deque <string> class_10;
    deque <string> class_11;
    int n; 
    while(cin>>n){
        if(n==9){
            string s;
            cin>>s;
            class_9.push_back(s);
        }else if(n==10){
            string s;
            cin>>s;
            class_10.push_back(s);
        }else if(n==11){
            string s;
            cin>>s;
            class_11.push_back(s);
        }else continue;        
    }
    while(!class_9.empty()){
        cout<<"9"<<" "<<class_9.front()<<endl;
        class_9.pop_front();
    }
    while(!class_10.empty()){
        cout<<"10"<<" "<<class_10.front()<<endl;
        class_10.pop_front();
    }
    while(!class_11.empty()){
        cout<<"11"<<" "<<class_11.front()<<endl;
        class_11.pop_front();
    }
    return 0;
}