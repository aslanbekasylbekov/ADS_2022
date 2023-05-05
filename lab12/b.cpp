#include <bits/stdc++.h>
#define V 200005
using namespace std; 

//Dijkstra's algorithm

const int INF = 1000000000; 
vector<pair<int,int>>g[200005]; 
vector<int> dist(V, INF); 
bool sptSet[V];

int Dijkstra(int s, int end){ 
    for(int i=0;i<V;i++){ 
        dist[i]=INF; sptSet[i]=false;
    } 
    dist[s] = 0; 
    set<pair<int,int>> setik; 
    setik.insert(make_pair(dist[s],s)); 
    while(!setik.empty()){ 
        int v = setik.begin()->second; 
        setik.erase(setik.begin()); 
        for(int j = 0;j<g[v].size();j++){ 
            int to = g[v][j].first; 
            int len = g[v][j].second; 
            if(dist[v]+len<dist[to]){ 
                setik.erase(make_pair(dist[to], to)); 
                dist[to] = dist[v] + len; 
                setik.insert(make_pair(dist[to], to)); 
            } 
        } 
    } 
    return dist[end]; 
} 
int main(){ 
    int n,m; cin>>n>>m; 
    for(int i=0;i<m;i++){
        int a,b,c; cin>>a>>b>>c; 
        g[a].push_back({b,c}); 
        g[b].push_back({a,c}); 
    } 
    int z,x,e,d; cin>>z>>x>>e>>d;  
    int a = Dijkstra(z,x) + Dijkstra(x,e) + Dijkstra(e,d); 
    int b = Dijkstra(z,e) + Dijkstra(e,x) + Dijkstra(x,d) ; 
    if(min(a,b)<=INF){
        cout<<min(a,b);
    } else{
        cout<<-1;
    }
    return 0;
}