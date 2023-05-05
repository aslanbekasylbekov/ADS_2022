#include <iostream>
#include <vector>
#include <set>
using namespace std;

int p[1000000];
int find(int v){
    if(p[v]==v) return v;
    else find(p[v]);
} 

void init_dsu(){
    for(int i=0;i<=10000;i++){
        p[i]=i;
    }
}

bool merge(int a,int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a==root_b) return true;
    else{
        p[root_a] = root_b;
        return false;
    }
}
int main(){
    init_dsu();
    merge(1,2);
    merge(2,3);
    merge(3,4);
    merge(5,6);
    merge(4,5);
    merge(4,5);
    merge(1,3);
    merge(1,2);
    merge(2,4);

    for(int i=1;i<=6;i++){
        cout<<p[i]<<" ";
    }
}