#include <iostream>
using namespace std;
int partition(int arr[], int low, int high, int pivot){
	int PIndex = low;
    for(int i=low;i<=high;i++) {   
        if(arr[i]<=pivot) {
            swap(arr[PIndex],arr[i]);
            PIndex++;
        }
    }
    PIndex--;
	return PIndex;
}
void Sort(int arr[], int low, int high){
	if(low < high) {
	    int pivot = arr[high];
	    int PIndex = partition(arr, low, high, pivot);
            Sort(arr, low, PIndex-1);
            Sort(arr, PIndex+1, high);
	}
}
int binarySearch(int a[],int l,int n, int x){
    int r=n-1,d=n;
    for(;l<= r;){
        int mid=l+(r-l)/2;
        if(a[mid]>x){
            r=mid-1;
            d=mid;
        }else l=mid+1;
    }
    return d;
}
int search(int a[],int n,int l,int r,int l1,int r1){
    int d=0,f=binarySearch(a,0,n,r)-binarySearch(a,0,n,l-1),s=binarySearch(a,0,n,r1)-binarySearch(a,0,n,l1-1);
    if(l1<=l && r1>=r) return s;
    else if(l<=l1 && r>=r1) return f;
    else if(l<r1 && r>=r1) d=(binarySearch(a,0,n,r1)-binarySearch(a,0,n,l-1));
    else if(l1<r && r1>=r) d=(binarySearch(a,0,n,r)-binarySearch(a,0,n,l1-1));
	return f+s-d;
}
int main() {
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  Sort(a, 0,n-1);
  for(int i=0;i<k;i++){
    int l,l1,r,r1;
    cin>>l>>r>>l1>>r1;
    cout<<search(a,n,l,r,l1,r1)<<endl;
  }
    return 0;
}