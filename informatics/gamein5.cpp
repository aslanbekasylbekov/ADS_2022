#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> first(5);
    deque<int> second(5);
    for(int i=0;i<5;i++){
        cin>>first[i];
    }for(int i=0;i<5;i++){
        cin>>second[i];
    }
    int cnt = 0;
    while(!first.empty() && !second.empty() && cnt<1000000){
        cnt++;
        int a = first.front();
        int b = second.front();
        first.pop_front();
        second.pop_front();
        if(a==9 && b==0){
            second.push_back(a);
            second.push_back(b);
        }else if(a==0 && b==9){
            first.push_back(a);
            first.push_back(b);
        }else if(a<b){
            second.push_back(a);
            second.push_back(b);
        }else if(a>b){
            first.push_back(a);
            first.push_back(b);
        }
    }
    if(first.empty()){
        cout<<"second "<<cnt;
    }else if(second.empty()){
        cout<<"first "<<cnt;
    }else{
        cout<<"botva";
    }
    return 0;
}