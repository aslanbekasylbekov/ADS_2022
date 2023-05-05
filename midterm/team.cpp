#include <iostream>
using namespace std;

struct heap{
        int * a;
        int size;
        heap(){
            a = new int[1000010];
            size = 0;
        }

        void heapify(int i){
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int mx = i;

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

        void insert(int x){
            a[size] = x;
            int i = size;
            size++;
            
            while(i > 0){
                int p = (i - 1)/2;

                if(a[p] < a[i]){
                    swap(a[p], a[i]);
                    i = p;
                } else break;
            }

        }
        int getSize(){
            return size;
        }
        int getMax(){
            return a[0];
        }
        void deleteMax(){
            swap(a[0], a[--size]);
            heapify(0);
        }

        void print(){
            for(int i=0; i<size; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        int f(){
            int first = getMax();
            deleteMax();
            int second = getMax();
            deleteMax();
            int third = getMax();
            deleteMax();
            insert(first);
            insert(second);
            insert(third);
            return first*second*third;
        }
        
};

int main(){
    int n; cin >> n;
    heap hp;
    int a[n];
    int ans = 0;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        hp.insert(x);
        if(hp.getSize() < 3){
            cout<<-1<<endl;
        } else{
            cout<<hp.f()<<endl;
        }
    }

}