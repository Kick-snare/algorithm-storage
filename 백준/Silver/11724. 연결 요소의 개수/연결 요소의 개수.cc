#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int curr) {
    if(visited[curr]) return;
    visited[curr] = true;
    for(auto &c : graph[curr]) dfs(graph, visited, c);
}

int main() {
    int N, M, u, v, count=0;
    cin >> N >> M;

    vector<vector<int>> graph(N+1, vector<int>());
    vector<bool> visited(N+1);

    while(M-- && cin >> u >> v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<N+1;i++) {
        if(visited[i]) continue;
        dfs(graph, visited, i);
        count++;
    }
    cout << count;
}