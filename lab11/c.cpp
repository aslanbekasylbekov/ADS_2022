#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int, pair<int, int>>> v;
int p[10000];

int find(int v){
    if(p[v]==v) return v;
    else{
        return p[v] = find(p[v]);
    } 
}
void init_dsu(){
    for(int i=0;i<=10000;i++){
        p[i]=i;
    }
}
void merge(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    p[root_a] = p[root_b];
}

int main(){
    int n, m, x ,y;
    cin >> n >> m >> x >> y;
    for(int i=1;i<=m;i++){
        string s;
        int a, b, c;
        cin >> s >> a >> b >> c;
        if(s == "both")v.push_back({c*min(x,y), {a, b}});
        else if(s == "small")v.push_back({c*y, {a, b}});
        else if(s == "big")v.push_back({c*x, {a, b}});
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    long long weight = 0;
    for(auto e : v){
        int l = e.second.second, r = e.second.first, c = e.first;
        if(find(l) != find(r)){
            weight += c;
            merge(l, r);
        }
    }
    cout << weight;


}