#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    cin >> N;
    vector<int> dp(N+1, 0);
    iota(dp.begin(), dp.end(), 0);

    for(int i=2;i<=N;i++) {
        if(i%3 == 0) dp[i] = min(dp[i], dp[i/3]);
        if(i%2 == 0) dp[i] = min(dp[i], dp[i/2]);
        dp[i] = min(dp[i], dp[i-1]) + 1;
    }
    cout << dp[N]-1 << endl;

    while(N>=1) {
        cout << N << ' ';
        if(dp[N] == dp[N-1] + 1) N-=1;
        else if(N%3 == 0 && dp[N] == dp[N/3] + 1) N/=3;
        else if(N%2 == 0 && dp[N] == dp[N/2] + 1) N/=2;
    }
}