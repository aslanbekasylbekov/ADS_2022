#include <iostream>
#include <vector>
using namespace std;
bool cmp(char a,char b){
    return a>b;
}
void quick_sort(vector <char>&a,int l,int r){
    if(r<l+1) return;
    int mid=(l+r)/2;
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
    vector <char> foo;
    for(int i=0;i<n;i++){
        char s; cin>>s;
        foo.push_back(s);
    }
    char x; cin>>x;
    quick_sort(foo,0,n-1);
    for(int i=0;i<n;i++){
        if(cmp(foo[i],x)){
            cout<<foo[i];
            return 0;       
        }
    }
    cout<<foo[0]<<endl;
}