#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main(){
    int n; cin>>n;
    vector <int> a(n);
    for(int i=0;i<a.size();i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    reverse(a.begin(),a.end());
    for(auto it = a.begin();it!=a.end();it++){
        cout<<a[1];
        return 0;
    }
    
}