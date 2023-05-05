#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
vector<int> g[MAXN];
bool used = true;
int color[MAXN];
int n,m,q;

void bfs(int v) {
    vector <int> visited(MAXN,0);
    vector <int> d(MAXN,0);
    queue<int>q;
    q.push(v);
    d[v] = 0;
    visited[v] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if(color[u]==1){
            cout<<d[u]<<endl;
            return;
        }
        for(auto i:g[u]){
            if(!visited[i]){
                visited[i]=1;
                d[i]=d[u]+1;
                q.push(i);
            }
        }
    }
    cout<<-1<<endl;
}

int main(){
    cin>>n>>m>>q;
    for (int i=0;i<m;i++) {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0;i<q;i++){
        int u,v; cin>>u>>v;
        if(u==1){
            color[v]=1;
            used=true;
        }
        else{
            if(!used){
                cout<<-1<<endl;
            } else bfs(v);
        }
    }
}