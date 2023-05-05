//example for BinarySearch
#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> foo,int n){
    int low = 0;
    int high = foo.size() - 1;
    while(low <= high){
        int center = (low + high) / 2;
        if(n == foo[center]){
            cout<<n<<" "<<center;
            return 0;
        }else if(n > foo[center]){
            low = center+1;
            cout<<n<<" "<<center;
            return 0;
        }else{
            high = center-1;
            cout<<n<<" "<<center;
            return 0;
        }
    }
    return 1;
}
int main(){
    vector <int> foo = {5,2,4,8,9,10,7,3};
    sort(foo.begin(),foo.end());
    binarySearch(foo,n);
    return 0;
}    