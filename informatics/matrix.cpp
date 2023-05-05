#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int min[n],max[m];
    for(int i=0;i<n;i++){
        min[i] = 1000;
        for(int j=0;j<m;j++){
            if(a[i][j]<min[i]){
                min[i]=a[i][j];
            }
        }
    }
    for(int j=0;j<m;j++){
        max[j] =- 1000;
        for(int i=0;i<n;i++){
            if(a[i][j]>max[j]){
                max[j]=a[i][j];
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(a[i][j]==min[i] && a[i][j]==max[j]){
                cnt++;
           }
        }
    }
    cout<<cnt<<" ";
}