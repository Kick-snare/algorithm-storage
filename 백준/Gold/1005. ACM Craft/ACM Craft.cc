#include <bits/stdc++.h>
using namespace std;
int T, N, K, X, Y, W;

int solve(vector<vector<int>> &adj, vector<int> &delay, vector<int> &indegree) {
    queue<int> q;
    for(int i=1;i<=N;i++) 
        if(!indegree[i]) q.push(i);
    
    int time = 0;
    vector<int> result(N+1);
    while(indegree[W]) {
        int curr = q.front();
        q.pop();

        for(auto &next : adj[curr]) {
            result[next] = max(result[next], result[curr] + delay[curr]);
            if(--indegree[next] == 0) q.push(next);
        }
    }
    return result[W] + delay[W];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;

    while(T--) {
        cin >> N >> K;
        vector<int> delay(N+1, 0), indegree(N+1, 0);
        vector<vector<int>> adj(N+1, vector<int>());
        
        for(int i=1;i<=N;i++) cin >> delay[i];
        while(K-- && cin >> X >> Y) {
            adj[X].push_back(Y);
            indegree[Y]++;
        }
        cin >> W;
        cout << solve(adj, delay, indegree) << '\n';
    }
}