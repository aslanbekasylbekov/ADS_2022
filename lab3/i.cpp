#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    sort(a,a+n);
    bool ok = false;
    int low = 0;
    int high = n-1;
    while((low<=high)&&(ok != true)){
        int center=(low+high)/2;
        if(a[center]==k) ok = true;
        if(a[center]>k) high=center-1;
        else low = center+1;
    }
    if(ok){
        cout<<"Yes";
        return 0;
    }
    cout<<"No";
}