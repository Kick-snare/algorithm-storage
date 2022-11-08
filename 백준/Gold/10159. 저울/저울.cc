#include <bits/stdc++.h>
using namespace std;
int N, M, a, b;

int main() {
    cin >> N >> M;
    vector<vector<bool>> adj(N+1, vector<bool>(N+1, false));

    while(cin >> a >> b) adj[a][b] = true;
    for(int i=1;i<=N;i++) adj[i][i] = true;

    for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
    for(int k=1;k<=N;k++)
        if(!adj[j][k]) adj[j][k] = adj[j][i] & adj[i][k];

    for(int i=1;i<=N;i++) {
        int count = 0;
        for(int j=1;j<=N;j++) {
            if(!adj[i][j] && !adj[j][i]) count++;
        }
        cout << count << endl;
    }
}