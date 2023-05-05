#include <iostream>
#include <vector>
using namespace std;
void quick_sort(vector <int> &a,int l,int r){
    if(r<l+1) return;
    int mid = (l+r)/2;
    int pivot = a[mid];
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
    int n; cin>>n;
    vector <int> foo(n);
    for(int i=0;i<n;i++){
        cin>>foo[i];
    }
    quick_sort(foo,0,n-1);
    int min=abs(foo[0]-foo[1]);
    for(int i=1;i<n;i++){
        if(abs(foo[i]-foo[i+1])<min){
            min=abs(foo[i]-foo[i+1]);
        }
    }
    for(int i=0;i<n-1;i++){
        if(abs(foo[i]-foo[i+1])==min){
            cout<<foo[i]<<" "<<foo[i+1]<<" ";
        }
    }
}