#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map <int,int> mp;
map <int,bool> used;
map <int,int> d;

void bfs(int n,int m){
    used[n] = true;
    queue <int> q;
    q.push(n);
    d[n]=0;
    while(!q.empty()){
        int v=q.front();
        if(!used[v-1]){
            mp[v-1]=v;
            used[v-1]=true;
            d[v-1]=d[v]+1;
            if(v-1==m) break;
            q.push(v-1);
        }
        if(!used[v*2] && ((v*2)/m)<2){
            mp[v*2]=v;
            used[v*2] = true;
            d[v*2] = d[v] + 1;
            if(v*2==m) break;
            q.push(v*2);
        }
        if(n==m)
            return;
        q.pop();
    }
}

int main(){
    int n,m; cin>>n>>m;
    bfs(n,m);
    cout<<d[m]<<endl;
    vector <int> ans;
    ans.push_back(m);

    while(mp[m]!=0){
        ans.push_back(mp[m]);
        m = mp[m];
    }
    reverse(ans.begin(),ans.end());
    for(int i=1;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}