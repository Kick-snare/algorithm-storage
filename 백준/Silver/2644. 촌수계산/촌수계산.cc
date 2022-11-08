#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p1, p2, m, t1, t2;
    cin >> n >> p1 >> p2 >> m;

    vector<vector<int>> relation(n+1, vector<int>());
    while(m-- && cin >> t1 >> t2) {
        relation[t1].push_back(t2);
        relation[t2].push_back(t1);
    }
    
    vector<int> visited(n+1, false);
    queue<pair<int, int>> q;
    q.emplace(p1, 0);
    visited[p1] = true;
    int curr, time;
    bool flag = false;

    while(!q.empty()) {
        curr = q.front().first, time = q.front().second;
        if(curr == p2) {
            flag = true;
            break;
        }
        q.pop();

        for(auto &node : relation[curr]) {
            if(visited[node]) continue;
            visited[node] = true;
            q.emplace(node, time+1);
        }
    }
    if(flag) cout << time;
    else cout << "-1";
}