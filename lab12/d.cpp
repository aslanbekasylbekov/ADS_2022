#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int INF = 1000000000;
const int mod = 100000000;

int p[1000000];
int r[1000000];
int x[1000000], y[1000000];

// void dijkstra(int graph[tt][tt], int src){
//     int dist[tt]; 
 
//     bool sptSet[tt]; 

//     for (int i = 0; i < tt; i++)
//         dist[i] = INT_MAX, sptSet[i] = false;
 
   
//     dist[src] = 0;
 
    
//     for (int count = 0; count < tt - 1; count++) {

//         int u = minDistance(dist, sptSet);
 
        
//         sptSet[u] = true;
 

//         for (int v = 0; v < tt; v++)
 

//             if (!sptSet[v] && graph[u][v]
//                 && dist[u] != INT_MAX
//                 && dist[u] + graph[u][v] < dist[v])
//                 dist[v] = dist[u] + graph[u][v];
//     }
 

// }

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

bool merge(int a,int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a==root_b) return true;
    else{
        if(r[root_a]<r[root_b]){
            p[root_a] = root_b;
        } else if(r[root_b]<r[root_a]){
            p[root_b] = root_a;
        }
        else{
            p[root_a] = root_b;
            r[root_b]++;
        }
        return false;
    }
}

void solve(int tc) {
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x[i]>>y[i];
	}
	int l=0,r=INF,ans;
	while(l<=r){
		int md =(l+r)/2;
		for(int i = 1; i <= n; i ++) p[i] = i;
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				if(abs(x[i]-x[j])+abs(y[i]-y[j]) <= md) merge(i , j);
			}
		}
		if(find(1) == find(n)) {
			ans = md;
			r = md-1;
		}
		else {
			l = md+1;
		}
	}
	cout << ans;
}

int main(){
    ios;
    int tt=1,tc=0;
    while(tt--){
        solve(++tc);
    }
}