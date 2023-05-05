#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int INF = 1000000000;
const int mod = 100000000;

int p[1000000];
int r[1000000];

int a[505][505];
int mn[505][505];
int x[1000000];
int u[1000000];

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

void solve(int tc){
    int n; cin>>n;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
			mn[i][j] = INF;
		}
	}
	for(int i=1;i<=n;i++) {
		cin>>x[i];
		int ans = 0;
		for(int j=1;j<=i;j++) {
			mn[x[j]][x[i]] = a[x[j]][x[i]];
			mn[x[i]][x[j]] = a[x[i]][x[j]];
		}
		for(int k=1;k<=i;k++) {
			for(int t=1;t<=i;t++) {
				mn[x[t]][x[i]] = min(mn[x[t]][x[i]] , mn[x[t]][x[k]] + mn[x[k]][x[i]]);
			}
		}
		for(int k=1;k<=i;k++) {
			for(int t=1;t<=i;t++) {
				mn[x[i]][x[t]] = min(mn[x[i]][x[t]] , mn[x[i]][x[k]] + mn[x[k]][x[t]]);
			}
		}
		for(int k=1;k<=i;k++) {
			for(int t=1;t<=i;t++) {
				mn[x[k]][x[t]] = min(mn[x[k]][x[t]] , mn[x[k]][x[i]] + mn[x[i]][x[t]]);
				if(mn[x[k]][x[t]]<INF) {
					ans = max(ans, mn[x[k]][x[t]]);
				}
			}
		}
		cout<<ans<<endl;
	}
}
int main() {
    ios;
    int tt=1,tc=0;
    while(tt--){
        solve(++tc);
    }
}