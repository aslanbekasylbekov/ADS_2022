#include <iostream>
using namespace std;
int Goblin(int a[],int n,int k){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]%k!=0)
            cnt=cnt+(a[i]/k)+1;
        else
            cnt=cnt+(a[i]/k);
    }
    return cnt;
}
int main(){
    int n,m; cin>>n>>m;
    int a1[n];
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    int l=0,r=1e9;
    while(l<=r){
        int mid=(l+r)/2;
        if(Goblin(a1,n,mid)<=m) r=mid-1;
        else l=mid+1;
    }
    cout<<l;
}