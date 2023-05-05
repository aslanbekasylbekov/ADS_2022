#include <iostream>
using namespace std;
bool isPrime(int n){
    if(n < 2) {
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int a; cin>>a;
    int n = 2;
    int cnt = 0;
    int cnt1 = 0;
    while(true){
        if(isPrime(n)){
            cnt++;
            if(isPrime(cnt)){
                cnt1++;
                if(cnt1 == a){
                    cout<<n;
                    break;
                }
            }
            
        }
        n++;
    }
}