#include <iostream>
#include <vector>
#include <set>
using namespace std;
//O(1)
int p[1000000];
int r[1000000];

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
    if(root_a==root_b) return false;
    p[root_a] = root_b;
    return true;
}
int main(){
    int n,m; cin>>n>>m;
    vector <int> g[n];
    for(int i = 0; i < n; i++){
        p[i] = i;
        r[i] = i;
    }
    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    
    }
    vector<long long> ans; 
    int cnt=0;
    for(int i=n-1;i>=0;i--){
        ans.push_back(cnt++);
        for(auto x:g[i]){
            if(x > i){
                if(merge(i, x)){
                    cnt--;
                }
            }
        }
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i]<<endl;
    }
}