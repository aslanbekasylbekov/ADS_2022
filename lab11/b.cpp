#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <pair<int,int>> graph[100000];
bool used[100000];
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        graph[1].push_back({i,a[1]+a[i]});
        graph[i].push_back({i,a[1]+a[i]});
    }
    int weight = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0,1});
    while(!q.empty()){
        pair<int,int> c=q.top();
        q.pop();

        int mst=c.first,v=c.second;
        if(used[v]) continue;
        used[v] = true;
        weight+=mst;
        for(pair<int,int> e:graph[v]){
            int u = e.first,lenght=e.second;
            if(!used[u]){
                q.push({lenght,u});
            }
        }
    }
    cout<<weight<<endl;
}