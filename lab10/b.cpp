#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> g[105];
bool used[105];
int d[105]; //d[i] = min distance start->i
int p[105]; //p[i] - parent

// void bfs(int v){
//     queue <int> q;
//     used[v] = true;
//     q.push(v);
//     d[v] = 0;
//     while(!q.empty()){
//         int u = q.front();
//         q.pop();
//         for(int i=0;i<g[u].size();i++){
//             int to = g[u][i];
//             if(!used[to]){
//                 q.push(to);
//                 used[to] = true;
//                 d[to] = d[u] + 1;//put'
//                 p[to] = u;//parent
//             }
//         }
//     }
// }
int main(){
    int n; //vertices
    // int m; //edges
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; cin>>x;
            if(x==1){
                g[i].push_back(j);
            }
        }
    }
    int s,f; cin>>s>>f;
    queue <int> q;
    q.push(s);
    used[s] = true;
    q.push(s);
    d[s] = 0;
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
    if(used[f]){
        cout<<d[f]<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}