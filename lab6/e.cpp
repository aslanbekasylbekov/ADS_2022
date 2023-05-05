#include <iostream>
#include <vector>
using namespace std;
int a[1000][1000];
int partition(int row,int l,int r){
    int pivot = a[r][row];
    int i=(l-1);
    for(int j=l;j<=r-1;j++){
        if(a[j][row]>pivot){
            i++;
            swap(a[i][row],a[j][row]);
        }
    }
    swap(a[i+1][row],a[r][row]);
    return (i+1);
}
void quick_sort(int row,int l,int r){
    if(l<r){
        int p=partition(row,l,r);
        quick_sort(row,l,p-1);
        quick_sort(row,p+1,r);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int row=0;row<m;row++){
        quick_sort(row,0,n-1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }    
}