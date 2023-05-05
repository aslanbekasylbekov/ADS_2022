#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector <int> g[MAXN];
bool used[MAXN];

void dfs(int v){
    used[v] = true;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        if(!used[to]) dfs(to);
    }
}
int main(){
    int n,m;
    cin>>n>>m;    
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int x,y; cin>>x>>y;
    dfs(x);
    if(used[y]) cout<<"YES";
    else cout<<"NO";
}