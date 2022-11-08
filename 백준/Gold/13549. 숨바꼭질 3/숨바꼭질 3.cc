#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<int> dp(100001, INT_MAX);

int main() {
    cin >> N >> K;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dp[N] = 0;
    pq.push({0, N});

    while(!pq.empty()) {
        int time = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        if(time > dp[curr]) continue;

        if(curr < 100000 && dp[curr+1] > time + 1){
            dp[curr+1] = time + 1;
            pq.push({time+1, curr+1});
        }
        if(curr > 0 && dp[curr-1] > time + 1){
            dp[curr-1] = time + 1;
            pq.push({time+1, curr-1});
        }
        if(curr*2 <= 100000 && dp[curr*2] > time){
            dp[curr*2] = time;
            pq.push({time, curr*2});
        }
    }

    cout << dp[K];
    // for(int i=0;i<=20;i++) cout << i << " : " << dp[i] << endl;
}