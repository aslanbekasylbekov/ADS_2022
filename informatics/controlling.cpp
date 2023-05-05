#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int a[100];
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    long long max =-1e9;
    long long min = 1e9;
    for(int i = 0; i < n; i++){
        if(a[i] > max)
            max = a[i];
        if(a[i] < min)
            min = a[i];
    }
    for(int i = 0; i < n; i++){
        if(a[i] == max)
            a[i] = min;
        cout << a[i] << " ";
    }
    return 0;
}