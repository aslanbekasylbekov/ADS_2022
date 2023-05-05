#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int check;
    for(int i=0;i<q;i++){
        int a,b,c; cin>>a>>b>>c;
        if(arr[a-1][b-1] && arr[a-1][c-1] && arr[b-1][c-1]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}