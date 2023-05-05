#include <iostream>
#include <vector>
using namespace std;
void quick_sort(vector <int>&a,int l,int r){
    if(r<l+1) return;
    int mid=(l+r)/2;
    int pivot=a[mid];
    int j=l;
    swap(a[r],a[mid]);
    for(int i=l;i<=r;i++){
        if(a[i]<pivot){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[j],a[r]);
    quick_sort(a,l,j-1);
    quick_sort(a,j+1,r);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> foo(n);
    vector<int> foo1(m);
    for(int i=0;i<n;i++){
        cin>>foo[i];
    }
    for(int j=0;j<m;j++){
        cin>>foo1[j];
    }
    quick_sort(foo,0,n-1);
    quick_sort(foo1,0,m-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(foo[i]==foo1[j]){
                cout<<foo[i]<<" ";
                foo1[j]=0;
                break;
            }
        }
    }
}