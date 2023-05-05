#include <iostream>
using namespace std;
int binarySearch(int a[], int x, int n){
    int ind=n,l=0,r=n-1;
    for(;l<=r;){
        int mid=l+(r-l)/2;
        if(a[mid] >= x){
            ind = mid;
            r = mid-1;
        }else{
			l = mid+1;
		}
    }
    return ind+1;
}
void sol(int m,int n,int a[]){
	for(;m!=0;m--){
        int x;
		cin>>x;
        cout << binarySearch(a, x, n) << endl;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
    	int d;
    	cin>>d;
        if(i == 0) a[i]=d;
        else a[i]=(d+a[i-1]);
    }
    sol(m,n,a);
}