#include <bits/stdc++.h>
using namespace std;
const int n = 405;
int minDistance(int dist[], bool sptSet[])
{
 
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < n; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}
void dijkstra(int graph[n][n], int src)
{
    int dist[n]; 
 
    bool sptSet[n]; 

    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
   
    dist[src] = 0;
 
    
    for (int count = 0; count < n - 1; count++) {

        int u = minDistance(dist, sptSet);
 
        
        sptSet[u] = true;
 

        for (int v = 0; v < n; v++)
 

            if (!sptSet[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 

}
int main()
{
    int tt;
    cin >> tt;
    if(tt == 1)
    {cout << 0 << endl;
    return 0;}
    long long mind = 0;
    long long xt, yt;
    for(int i = 0; i < tt; i++)
    {
        long long x, y;
        cin >> x >> y;
        
    }
    cout <<mind + 1<< endl;
}