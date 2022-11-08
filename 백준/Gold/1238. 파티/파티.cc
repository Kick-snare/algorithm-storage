#include <bits/stdc++.h>
using namespace std;
int N, M, X, start, dest, dist;
using pii = pair<int, int>;
vector<pii> adj[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int dijkstra(int start, int place) {
    if(start == place) return 0;
    
    vector<int> dp(N+1, INT_MAX);
    pq.push({0, start});
    dp[start] = 0;

    while(!pq.empty()) {
        int curr = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();
        if(curr_dist > dp[curr]) continue;
        
        for(auto &edge : adj[curr]) {
            int next = edge.second;
            int next_dist = dp[curr] + edge.first;
            if(next_dist >= dp[next]) continue;
            dp[next] = next_dist;
            pq.push({next_dist, next});
        }
    }
    return dp[place];
}

int main() {
    cin >> N >> M >> X;
    for(int i=0;i<M;i++) {
        cin >> start >> dest >> dist;
        adj[start].emplace_back(dist, dest);
    }
    int result = 0;
    for(int i=1;i<=N;i++) result = max(result, dijkstra(i, X) + dijkstra(X, i));
    cout << result;
}