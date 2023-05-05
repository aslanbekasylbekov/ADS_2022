#include <iostream>
using namespace std;
int c[1000000];
void mergeTwo(int a[],int b[],int n,int m){
    int i,j,k;
    i=j=k=0;
    while(i<n && j<m){
        if(a[i]<b[j]){
            c[k]=a[i];
            k++;i++;
        } else{
            c[k]=b[j];
            k++;j++;
        }
    }
    for(;i<n;i++){
        c[k]=a[i];
        k++;    
    }
    for(;j<m;j++){
        c[k]=b[j];
        k++;
    }
}
int main(){
    int a[4] = {2,4,5,7};
    int b[6] = {1,3,5,8,9,10};
    mergeTwo(a,b,4,6);
    for(int i=0;i<10;i++){
        cout<<c[i]<<" ";
    }
}