#include <iostream>
using namespace std;

struct heap{
    private:
        unsigned long long * a;
        unsigned long long size;
    public:
        heap(){
            a = new unsigned long long[1000010];
            size = 0;
        }

        void heapify(unsigned long long i){
            unsigned long long l = 2 * i + 1;
            unsigned long long r = 2 * i + 2;
            unsigned long long mx = i;

            if(l < size && a[l] > a[mx]){
                mx = l;
            }

            if(r < size && a[r] > a[mx]){
                mx = r;
            }

            if(mx != i){
                swap(a[mx], a[i]);
                heapify(mx);
            }
        }

        void insert(unsigned long long x){
            a[size] = x;
            unsigned long long i = size;
            size++;
            
            while(i > 0){
                unsigned long long p = (i - 1)/2;

                if(a[p] < a[i]){
                    swap(a[p], a[i]);
                    i = p;
                } else break;
            }

        }
        unsigned long long getMax(){
            return a[0];
        }
        void deleteMax(){
            swap(a[0], a[--size]);
            heapify(0);
        }
        unsigned long long getSize(){
            return size;
        }

        void print(){
            for(int i=0; i<size; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    unsigned long long n,x; cin >> n>>x;
    heap hp;
    unsigned long long a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        hp.insert(a[i]);
    }
    unsigned long long sum = 0;
    for(int i=0;i<x;i++){
        unsigned long long seat=hp.getMax();
        hp.deleteMax();
        sum+=seat;
        seat--;
        hp.insert(seat);
    }
    cout<<sum;
    return 0;
}