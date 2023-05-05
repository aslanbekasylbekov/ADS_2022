#include <iostream>
using namespace std;

void mergeTwo(int a[],int b[],int n,int m){
    int i = 0;
    int j = 0;

    while(i<n && j<m){
        if(a[i] < b[j]){
            cout << a[i++] << " ";
        } else{
            cout << b[j++] << " ";
        }
    }
    while(i<n){
        cout << a[i++] << " ";
    }
    while(j<m){
        cout << b[j++] << " ";
    }
}
int main(){
    int n; cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int m; cin >> m;
    int b[m];

    for(int j=0;j<m;j++){
        cin>>b[j];
    }

    mergeTwo(a, b, n, m);
    return 0;
}