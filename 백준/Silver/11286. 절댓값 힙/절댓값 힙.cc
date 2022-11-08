#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;
    int N, x;
    cin >> N;
    while(N-- && cin >> x) {
        if(x!=0) pq.push({abs(x), x>0});
        else {
            if(pq.empty()) cout << "0\n";
            else {
                if(pq.top().second) cout << pq.top().first << '\n';
                else cout << '-' << pq.top().first << '\n';
                pq.pop();
            }
        }
    }
}