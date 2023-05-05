#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 105;
char a[MAXN][MAXN];
bool used[MAXN][MAXN];

void dfs(int i,int j){
    if(i<1 || j<1 ||i>n || j>m) return;
    if(used[i][j]) return;
    if(a[i][j]=='0') return;
    used[i][j] = true;
    dfs(i,j+1);//right
    dfs(i,j-1);//left
    dfs(i-1,j);//up
    dfs(i+1,j);//down
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='1' && !used[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt;
}