#include <iostream>
using namespace std;

int newPos;
int val;

struct heap{
    public:
        int *a;
        int size;
        heap(){
            a = new int[1000010];
            size = 0;
        }

        void heapify(int i){
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int mx = i;
            

            if(l<size && a[l]>a[mx]){
                mx = l;
            }
            if(r<size && a[r]>a[mx]){
                mx = r;
            }
            if(mx!=i){ 
                swap(a[mx],a[i]);
                if(a[i] == val){
                    newPos = i;
                }
                heapify(mx);
            }
        }
        void insert(int x){
            a[size] = x;
            int i = size;
            size++;

            while(i > 0){
                int p = (i-1)/2;
                if(a[p]<a[i]){
                    swap(a[p],a[i]);
                    i = p;
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
            for(int i=size/2; i>=0; i--){
                heapify(i);
            }
        }

        void update(int x, int pos){
            a[pos-1]+=x;
            newPos = pos-1;
            val = a[pos-1];
            build();
        }
};
int main(){
    heap hp;
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        hp.insert(a[i]);
    }

    int k; cin >> k;
    while(k--){
        int x, pos; cin >> pos >> x;
        hp.update(x, pos);
        cout << newPos + 1 << endl; 
    }

    hp.print();
    return 0;
}