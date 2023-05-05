#include <iostream>
using namespace std;
struct heap{
    unsigned long long val;
    unsigned long long *a;
    unsigned long long size;
    heap(){
        a = new unsigned long long[1000010];
        size = 0;
    }
    void heapify(unsigned long long i){
        unsigned long long l = 2 * i + 1;
        unsigned long long r = 2 * i + 2;
        unsigned long long mx = i;
        if(l<size && a[l]<a[mx]){
            mx = l;
        }
        if(r<size && a[r]<a[mx]){
            mx = r;
        }
        if(mx != i){
            swap(a[mx],a[i]);
            heapify(mx);
        }
    }
    void insert(unsigned long long x){
        a[size] = x;
        unsigned long long i = size;
        size++;
        
        while(i>0){
            unsigned long long p = (i - 1)/2;
            if(a[p]>a[i]){
                swap(a[p],a[i]);
                i = p;
            } else break;
        }
    }
    unsigned long long getMin(){
        return a[0];
    }
    void deleteMin(){
        swap(a[0],a[--size]);
        heapify(0);
    }
    unsigned long long getSize(){
        return size;
    }
        
    void print(){
        for(unsigned long long i=0;i<size;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    heap hp;
    unsigned long long n,k; cin>>n>>k;
    unsigned long long a[n];
    for(unsigned long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(unsigned long long i=0;i<n;i++){
        hp.insert(a[i]);
    }
    unsigned long long cnt=0;
    bool ok = false;
    while(hp.getSize()>1){
        int first = hp.getMin();
        hp.deleteMin();
        if(first>=k){
            ok=true;
            break;
        }
        int second = hp.getMin();
        hp.deleteMin();
        int newElement = first+2*second;
        hp.insert(newElement);
        cnt++;
        if(newElement>=k){
            ok=true;
        }
    }
    if(ok){
        cout<<cnt<<" ";
    } else {
        cout<<-1<<" ";
    }
}