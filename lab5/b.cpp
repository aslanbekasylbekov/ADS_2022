#include <iostream>
using namespace std;

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
        int getSize(){
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
    int n; cin >> n;
    heap hp;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        hp.insert(a[i]);
    }
    int ans = 0;
    while(hp.getSize()>1){
        int first = hp.getMax();
        hp.deleteMax();
        int second = hp.getMax();
        hp.deleteMax();
        if(first!=second){
            ans = first-second;
            hp.insert(ans);
        } 
    }

    if(hp.getSize() == 0){
        cout << 0;
    } else cout << hp.getMax();

    return 0;
}