#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void quick_sort(vector <char>&a,int l,int r){
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
    vector <char> foo;
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        foo.push_back(s[i]);
    }
    quick_sort(foo,0,foo.size()-1);
    for(auto i:foo){
        cout<<i;
    }
}