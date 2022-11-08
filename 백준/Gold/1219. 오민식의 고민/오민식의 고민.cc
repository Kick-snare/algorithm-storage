#include <bits/stdc++.h>
using namespace std;
int N, start, dest, M, S, E, C;
using tiii = tuple<int, int, int>;
vector<long long> city, money(50, LLONG_MIN);
vector<tiii> edges;
bool flag = false;

void input() {
    cin >> N >> start >> dest >> M;
    for(int i=0;i<M;i++) {
        cin >> S >> E >> C;
        edges.emplace_back(S, E, C);
    }
    while(cin >> C) city.push_back(C);
}

bool bfs(int node) {
    if(node == dest) return true;
    vector<int> visited(N, false);
    queue<int> q;
    visited[node] = true;
    q.push(node);
    int from, to, cost;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto &edge : edges) {
            tie(from, to, cost) = edge;
            if(from != curr || visited[to]) continue;
            if(to == dest) return true;
            visited[to] = true;
            q.push(to);
        }
    }
    return false;
}

void BF() {
    money[start] = city[start];
    long long from, to, cost;

    for(int i=0;i<N;i++) {for(auto &edge : edges) {
        tie(from, to, cost) = edge;
        if(money[from] == LLONG_MIN) continue;

        if(money[to] < money[from] - cost + city[to]) {
            money[to] = money[from] - cost + city[to];

            if(i!=N-1) continue;
            if(bfs(to)) flag = true;
        }
        } 
        // for(int i=0;i<N;i++) cout << money[i] << ' ';  cout <<endl;
    }
}

int main() {
    input();
    BF();

    if(money[dest] == LONG_MIN) cout << "gg";
    else if(flag) cout << "Gee";
    else cout << money[dest];
}   