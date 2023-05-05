#include <iostream>
using namespace std;
long long n , k, X[300000],Y[300000],d=1e9;
int s(){
    long long l=0,r=d;
    for(;l+1<r;){
        int cnt=0;
        int mid=(r+l)/2;
        for(int i=0;i<n;i++){
			if(mid>=X[i] && mid>=Y[i]) cnt++;
		}
        if(k==cnt || cnt > k) r= mid;
        else l=mid;
    }
    return r;
}
int main(){
    cin>>n>>k; 
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y>>X[i]>>Y[i];
    }
    cout << s();
}