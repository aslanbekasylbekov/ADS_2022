#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>g;
vector<int> g2;

bool find_cl(int v, pair<int, int> edge){
    g2[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if(v == edge.first and u == edge.second){
            continue;
        } 
        if(g2[u] == 1){
            return 1;
        }
        if(g2[u] == 0){
            if (find_cl(u, edge)){
               return 1;
            }
        }
    }
    g2[v] = 2;
    return 0;
}
int main() {
    int m, n;
    cin >> m >> n;
    g2.resize(m);
    g.resize(m);
    while(n--){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < g[i].size(); j++){
            bool found_cl = false;
            for(int l = 0; l < m; l++){
                if(find_cl(l, {i, g[i][j]})){
                found_cl = true;
                break;
            }
        }
        if(found_cl == false){
            cout << "YES";
            return 0;
        }
        g2.assign(m, 0);
        }
    }
    cout << "NO";
    return 0;
}