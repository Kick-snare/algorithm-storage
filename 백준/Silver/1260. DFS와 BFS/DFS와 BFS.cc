#include <bits/stdc++.h>
using namespace std;
int N, M, V, n1, n2;
vector<set<int>> graph(1001, set<int>());

void dfs() {
    vector<bool> visited(1001);
    stack<int> stk;
    visited[V] = true;
    stk.push(V);
    cout << V << ' ';

    while(!stk.empty()) {
        int curr = stk.top();
        bool flag = false;

        for(auto &node : graph[curr]) {
            if(visited[node]) continue;
            cout << node << ' ';
            stk.push(node);
            visited[node] = true;
            flag = true;
            break;
        }
        if(!flag) stk.pop();
    }
    cout << '\n';
}

void bfs() {
    vector<bool> visited(1001);
    queue<int> que;
    visited[V] = true;
    que.push(V);
    cout << V << ' ';

    while(!que.empty()) {
        int curr = que.front();
        que.pop();
        
        for(auto &node : graph[curr]) {
            if(visited[node]) continue;
            cout << node << ' ';
            visited[node] = true;
            que.push(node);
        }
    }
}

int main() {
    cin >> N >> M >> V;
    while(M--) {
        cin >> n1 >> n2;
        graph[n1].insert(n2);
        graph[n2].insert(n1);
    }
    
    dfs();
    bfs();
}