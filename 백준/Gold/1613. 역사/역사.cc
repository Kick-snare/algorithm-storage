#include<bits/stdc++.h>
using namespace std;
int n, k, s, a, b;
using pii = pair<int, int>;

int main() {
    cin >> n >> k;
    vector<vector<bool>> relation(n+1, vector<bool>(n+1, false));
    vector<pii> q;

    for(int i=1;i<=k;i++) {
        cin >> a >> b;
        relation[a][b] = true;
        if(i<=n) relation[i][i] = true;
    }

    cin >> s;
    while(s-- && cin >> a >> b) q.emplace_back(a, b);

    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    for(int k=1;k<=n;k++) 
        if(!relation[j][k]) relation[j][k] = relation[j][i] & relation[i][k];

    int from, to;
    for(auto &query : q) {
        tie(from, to) = query;
        if(!relation[from][to] && !relation[to][from]) cout << "0\n";
        else if(relation[from][to]) cout << "-1\n";
        else cout << "1\n";
    }
}