#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

int p[1000000];
int find(int v){
    if(p[v]==v) return v;
    else find(p[v]);
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
        p[root_a] = root_b;
        return false;
    }
}
int main(){
    int n,m; cin>>n>>m;
    vector<pair<int,pair<int,int>>>graph;
    int mst = 2;
    for(int i=0;i<m;i++){
        int l,r,c; cin>>l>>r>>c;
        graph.push_back(make_pair(c,make_pair(l,r)));
    }
    long long cnt = 0;
    sort(graph.begin(),graph.end());
    while(mst<=n){
        for(auto e:graph){
            int a=e.second.first;
            int b=e.second.second;
            int z=e.first;
            if(a<mst && mst<=b){
                cnt+=z;
                mst++;
                break;
            }
        }
    }
    cout<<cnt;
}