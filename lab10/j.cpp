#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// const int MAXN = 100005;
// vector <int> g[MAXN];
// bool used[MAXN];

// void dfs(int v){
//     cout<<v<<" "<<endl;
//     used[v] = true;
//     for(int i=0;i<g[v].size();i++){
//         int to = g[v][i];
//         if(!used[to]) dfs(to);
//     }
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         int u,v; cin>>u>>v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     for(int i=1;i<=n;i++){
//         if(!used[i]){
//             dfs(i);
//         }
//     }
// }

const int MAXN = 100005;
vector <int> g[MAXN];
bool used[MAXN];

int cnt=0;
void dfs(int v){
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(g[v].size()<g[to].size()){
            cnt++;
        }
        dfs(to);
    }
}

int main(){
    int n,m; cin>>n>>m;
    int k=0;
    while(k<m){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        k++;
    }
    k=1;
    while(k<=n){
        if(!used[k]){
            dfs(k);
            cnt++;
        }
        k++;
    }
    cout<<cnt;
}