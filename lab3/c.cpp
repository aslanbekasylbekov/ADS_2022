#include <iostream>
using namespace std;
int bs(int a[],int n,int l1,int r1,int l2,int r2){
    int cnt=0;
    for(int i=0;i<n;i++){
        if((l1<=a[i] && r1>=a[i])||(l2<=a[i] && r2>=a[i])){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int n,k; cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[4];
    for(int i=0;i<k;i++){
        for(int j=0;j<4;j++){
            int c; cin>>c;
            b[j]=c;
        }
        cout<<bs(a,n,b[0],b[1],b[2],b[3])<<endl;
    }
    return 0;
}