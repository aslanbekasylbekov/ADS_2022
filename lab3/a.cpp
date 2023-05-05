#include <iostream>
using namespace std;
int bs_odd(int a[],int x,int low,int high){
    int mid=(low+high)/2;
    if(low<=high){
        if(a[mid]==x) return mid;
        else if(a[mid]<x){
            return bs_odd(a,x,mid+1,high);
        } else{
            return bs_odd(a,x,low,mid-1);
        }
    } else{
        return -1;
    }
    
}
int bs_even(int a[],int x,int low,int high){
    int mid=(low+high)/2;
    if(low<=high){
        if(a[mid]==x) return mid;
        else if(a[mid]<x){
            return bs_even(a,x,low,mid-1);
        } else{
            return bs_even(a,x,mid+1,high);
        }
    }
    else {
        return -1;
    }
}
int main(){
    int n; cin>>n;
    int a1[n];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    int m,k;
    cin>>m>>k;
    int a2[m][k];
    for(int i=0;i<m;i++){
        for(int j=0;j<k;j++){
            cin>>a2[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j%2==1){
                int b = bs_odd(a2[j],a1[i],0,k-1);
                if(b!=-1){
                    cout<<j<<" "<<b<<endl;
                    break;
                } else if(b==-1 && j==m-1){
                    cout<<-1<<endl;
                }
            }else {
                int b = bs_even(a2[j],a1[i],0,k-1);
                if(b!=-1){
                    cout<<j<<" "<<b<<endl;
                    break;
                } else if(b==-1 && j==m-1){
                    cout<<-1<<endl;
                }
            }
        }
    }
}