#include <bits/stdc++.h>
using namespace std;
int dp[50001];

int main() {
    int num;
    cin>>num;
    dp[1] = 1;

    for(int i=1;i<=num;i++) {
        dp[i] = dp[i-1] + dp[1];
        for(int j=2;j*j<=i;j++) dp[i] = min(dp[i], dp[i-j*j] + 1);
    }
    cout<<dp[num];
}