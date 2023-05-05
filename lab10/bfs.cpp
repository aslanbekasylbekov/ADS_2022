#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> g[105];
bool used[105];
int d[105]; //d[i] = min distance start->i
int p[105]; //p[i] - parent

void bfs(int v){
    queue <int> q;
    used[v] = true;
    q.push(v);
    d[v] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int to = g[u][i];
            if(!used[to]){
                q.push(to);
                used[to] = true;
                d[to] = d[u] + 1;//put'
                p[to] = u;//parent
            }
        }
    }
}
int main(){
    int n; //vertices
    int m; //edges
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<d[i]<<" "<<p[i]<<endl;
    }
}