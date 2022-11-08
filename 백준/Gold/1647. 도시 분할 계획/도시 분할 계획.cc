#include <bits/stdc++.h>
using namespace std;
int N, M, A, B, C;
using tiii = tuple<int, int, int>;
set<tiii> edges;
vector<int> parent(100001);
int set_num;

int findParent(int v){
    if(parent[v] == v) return v;
    return parent[v] = findParent(parent[v]);
}
void mergeSet(int a, int b) {
    int A = findParent(a), B = findParent(b);
    if(A != B) parent[B] = A;
    set_num--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;
    set_num = N;

    while(cin >> A >> B >> C) edges.emplace(C, A, B);
    for(int i=1;i<=N;i++) parent[i] = i;

    int cost, from, to, answer = 0;
    for(auto &edge : edges) {
        tie(cost, from, to) = edge;
        if(findParent(from) == findParent(to)) continue;
        mergeSet(from, to);
        answer += cost;
        if(set_num == 2) break;
    }
    cout << answer;
}