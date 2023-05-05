#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int kcnt=0, scnt=0 ,j=0;
    queue <char> foo;
    char ks;
    for(int i=0;i<n;i++){
        cin>>ks;
        foo.push(ks);
        if(ks=='K'){
            kcnt++;
        }else{
            scnt++;
        }
    }
    for(int i=0;foo.size()!=1;i++){
        if(foo.front()=='K'){
            if(j<=0){
                foo.push(foo.front());
            }else{
                kcnt--;
            }
            j--;
        }else{
            if(j>=0){
                foo.push(foo.front());
            }else{
                scnt--;
            }
            j++;
        }
        if(kcnt==0 or scnt==0){
            break;
        }
        foo.pop();  
    }
    if(kcnt>scnt){
        cout<<"KATSURAGI";
    }else{
        cout<<"SAKAYANAGI";
    } 
}