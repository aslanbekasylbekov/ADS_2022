#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e+5;
vector <int> g[MAXN];

int n,m;
int NEW=0;
int DURING=1;
int VISITED=2;
int state[MAXN];

vector <int> ans;
void dfs(int v){    
    if(state[v]==DURING){
        cout<<"Impossible"<<endl;
        exit(0);
    }
    if(state[v]==VISITED) return; 
    state[v] = DURING;
    for(int i=0;i<g[v].size();i++){
        int to = g[v][i];
        dfs(to);
    }
    state[v] = VISITED;
    ans.push_back(v);
}
void topSort(){
    for(int i=0;i<n;i++){
        state[i] = false;
    }
    ans.clear();
    for(int i=0;i<n;i++){
        if(!state[i]) dfs(i);
    }
    reverse(ans.begin(),ans.end());
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
    }
    for(int i=1;i<=n;i++){
        if(state[i]==NEW) dfs(i);
    }
    cout<<"Possible"<<endl;
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}