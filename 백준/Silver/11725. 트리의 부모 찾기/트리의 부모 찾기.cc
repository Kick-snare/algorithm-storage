#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, v1, v2;
    cin >> N;
    vector<int> parent(N+1, 0);
    parent[1] = 1;
    vector<vector<int>> tree(N+1, vector<int>());

    while(cin >> v1 >> v2) {
        tree[v1].push_back(v2);
        tree[v2].push_back(v1);
    }

    stack<int> s;
    vector<bool> visited(N+1, false);
    s.push(1);
    visited[1] = true;

    while(!s.empty()) {
        int curr = s.top();
        bool flag = false;

        for(auto &node : tree[curr]) {
            if(visited[node]) continue;
            visited[node] = true;
            parent[node] = curr;
            s.push(node);
            flag = true;
            break;
        }

        if(!flag) s.pop();
    }

    for(int i=2;i<=N;i++) cout << parent[i] << '\n';
}