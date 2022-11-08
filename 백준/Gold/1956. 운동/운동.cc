#include <bits/stdc++.h>
using namespace std;
int V, E, a, b, c;

int main() {
    cin >> V >> E;
    vector<vector<int>> adj(V+1, vector<int>(V+1, INT_MAX));

    while(cin >> a >> b >> c) adj[a][b] = c;
    for(int i=1;i<=V;i++) adj[i][i] = 0;

    for(int i=1;i<=V;i++)
    for(int j=1;j<=V;j++)
    for(int k=1;k<=V;k++) {
        if(adj[j][i]==INT_MAX || adj[i][k]==INT_MAX) continue;
        adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
    }

    int min_cycle = INT_MAX;
    for(int i=2;i<=V;i++) {
        for(int j=1;j<i;j++) {
            if(adj[j][i]==INT_MAX || adj[i][j]==INT_MAX) continue;
            min_cycle = min(min_cycle, adj[i][j] + adj[j][i]);
        }
    }
    if(min_cycle == INT_MAX) cout << "-1";
    else cout << min_cycle;
}