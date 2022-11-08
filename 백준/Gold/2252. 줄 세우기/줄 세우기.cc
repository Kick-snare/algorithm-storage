#include <bits/stdc++.h>
using namespace std;
int N, M, A, B, indegree[32001];
vector<int> adj[320001];

int main() {
    cin >> N >> M;
    while(cin >> A >> B) {
        adj[A].push_back(B);
        indegree[B]++;
    }

    queue<int> q;
    for(int i=1;i<=N;i++) 
        if(!indegree[i]) q.push(i);

    vector<int> result;
    while(!q.empty()) {
        int curr = q.front();
        result.push_back(curr);
        q.pop();

        for(auto &next : adj[curr])
            if(--indegree[next] == 0) q.push(next);
    }

    for(auto &w : result) cout << w << ' ';
}