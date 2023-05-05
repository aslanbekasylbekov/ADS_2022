#include <iostream>
#include <stack>
using namespace std;

struct heap{
    public:
        int *a;
        int size;
        heap(){
            a = new int[1000010];
            size=0;
        }

        void heapify(int i){
            int l=2*i+1;
            int r=2*i+2;
            int mx=i;

            if(l<size && a[l]>a[mx]){
                mx=l;
            }
            if(r<size && a[r]>a[mx]){
                mx=r;
            }
            if(mx!=i){
                swap(a[mx],a[i]);
                heapify(mx);
            }
        }
        void insert(int x){
            a[size] = x;
            int i=size;
            size++;

            while(i>0){
                int p = (i-1)/2;
                if(a[p]<a[i]){
                    swap(a[p],a[i]);
                    i=p;
                } else break;
            }
        }
        int getMax(){
            return a[0];
        }
        void deleteMax(){
            swap(a[0],a[--size]);
            heapify(0);
        }
        void print(){
            for(int i=0;i<size;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        void build(){
            for(int i=size/2;i>=0;i--){
                heapify(i);
            }
        }
};
int main(){
    heap hp;
    stack <int> foo;
    int n; cin>>n;
    for(int i=0;i<n;i++){
        string s; cin>>s;
        if(s=="add"){
            int t; cin>>t;
            foo.push(t);
            hp.insert(t);
        }
        if(s=="delete"){
            if(foo.empty()) continue;
            if(hp.getMax() == foo.top()){
                hp.deleteMax();
                foo.pop();
            } else{
                foo.pop();
            }         
        }
        if(s=="getmax"){
            if(foo.empty()){
                cout<<"error\n";
            }else{
                cout<<hp.getMax()<<endl;
            }      
        }
        if(s=="getcur"){
            if(foo.empty()){
                cout<<"error\n";
            }else{
                cout<<foo.top()<<endl;
            }
        }
    }
}