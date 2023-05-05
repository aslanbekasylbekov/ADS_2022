#include <iostream>
using namespace std;
bool check(long long a[],int n,long long k,long long target){
    long long blocks = 0,sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>target) return false;
        sum+=a[i];
        if(sum==target){
            blocks++;
            sum=0;
        } else if(sum>target){
            blocks++;
            sum=a[i];
        }
    }
    if(sum>0) blocks++;
    return blocks<=k;
}   
int main(){
    int n,k; cin>>n>>k;
    long long a[n];
    long long l=0,r=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        r+=a[i];
        if(a[i]>l) l=a[i];
    }
    long long temp;
    while(l<=r){
        long long m=(l+r)/2;
        if(check(a,n,k,m)){
            temp = m;
            r=m-1;
        } else{
            l=m+1;
        }
    }
    cout<<temp;
}