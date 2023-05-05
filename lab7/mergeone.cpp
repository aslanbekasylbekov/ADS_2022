#include <iostream>
using namespace std;
int b[1000000];
void mergeOne(int a[],int l,int mid,int r){
    int i,j,k;
    i=j=k=0;
    i=l;
    j=mid+1;
    k=l;
    int b[r+1];
    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k]=a[i];
            k++;i++;
        }
        else{
            b[k]=a[j];
            k++;j++;
        }
    }
    for(;i<=mid;i++){
        b[k] =a[i];
        k++;
    }
    for(;j<=r;j++){
        b[k]=a[j];
        k++;
    }
    for(int i=l;i<=r;i++){
        a[i]=b[i];
    }
}
int main(){
    int a[8]={2,5,8,6,7,9,10,12};
    mergeOne(a,0,2,8);
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }
}