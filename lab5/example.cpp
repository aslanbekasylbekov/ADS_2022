#include <iostream>

using namespace std;
//heapMax
struct heap{
    private:
        int * a;
        int size;
    public:
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
};

int main(){
    int n; cin >> n;
    heap hp;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        hp.insert(x);
    }

    hp.print();
    hp.deleteMax();
    hp.print();
    hp.insert(15);
    hp.print();
    return 0;
}