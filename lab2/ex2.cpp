#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int sum = 0;
        while(a[i]!=0){
            sum = sum+a[i]%10;
            a[i]/=10;
        }
        if(sum%2==0){
            cout<<"Sum of digits is even!\n";
        }else{
            cout<<"Sum of digits is odd!\n";
        }
    }  
}