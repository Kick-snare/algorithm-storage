#include <bits/stdc++.h>
using namespace std;
int N, x;

int main() {
    cin >> N;
    vector<pair<int, int>> X;
    vector<int> result(N);

    for(int i=0;cin >> x;i++) X.push_back({x, i});
    sort(X.begin(), X.end());

    int count = 0;
    for(auto it=X.begin(); it!=X.end(); it++) {
        result[it->second] = count;
        if(next(it, 1) != X.end() && it->first < next(it, 1)->first) count++;
    }

    // for(auto &s : X) cout << s.first << ' ' << s.second << endl;

    for(auto &w : result) cout << w << ' ';
}