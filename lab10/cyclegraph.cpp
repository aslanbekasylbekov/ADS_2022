#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector <int> g[MAXN];
int NEW=0;
int DURING=1;
int VISITED=2;
int state[MAXN];
void dfs(int v){    
    if(state[v]==DURING){
        cout<<"Cycle detected"<<endl;
        exit(0);
    }
    if(state[v]==VISITED) return; 
    state[v] = DURING;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        dfs(to);
    }
    state[v] = VISITED;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(state[i]==NEW) dfs(i);
    }
    cout<<"Graph is acyclic"<<endl;
}