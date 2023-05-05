#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;

const int MAXN = 1005;
int a[MAXN][MAXN];
bool used[MAXN][MAXN];
// int d[MAXN]; //d[i] = min distance start->i
// int p[MAXN]; //p[i] - parent

int x[4] = {1,0,-1,0};
int y[4] = {0,1,0,-1};

int main(){
    // int n; //vertices
    // int m; //edges
    vector<queue<pair<int,int>>>v;
    cin>>n>>m;
    int griby = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]==2){
                v.push_back(queue<pair<int,int>>());
                v[v.size()-1].push({i,j});
                used[i][j] = true;
            }
            else if(a[i][j]==1){
                griby++;
            }
        }
    }
    if(griby==0){
        cout<<0;
        return 0;
    }
    int cnt=0;
    while(true){
        bool empty = true;
        for(int i=0;i<v.size();i++){
            if(!v[i].empty()){
                queue<pair<int,int>> cur = v[i];
                while(!cur.empty()){
                    empty=false;
                    int vx = cur.front().first;
                    int vy = cur.front().second;
                    cur.pop();
                    v[i].pop();
                    for(int k=0;k<4;k++){
                        int vx1 = vx+x[k];
                        int vy1 = vy+y[k];
                        if(vx1>0 && vy1>0 && vx1<=n && vy1<=m){
                            if(!used[vx1][vy1] && a[vx1][vy1]!=0){
                                used[vx1][vy1] = true;
                                if(a[vx1][vy1]==1){
                                    griby--;
                                    if(griby==0){
                                        cout<<cnt+1<<endl;
                                        return 0;
                                    }
                                }
                                a[vx1][vy1] = 2;
                                v[i].push({vx1,vy1});
                            }
                            
                        }
                    }
                }
            }
        }
        if(empty) break;
        cnt++;
    }
    cout<<-1;
}