#include <bits/stdc++.h>
using namespace std;
int T, N;

int main() {
    cin >> T;
    while(T-- && cin >> N) {
        vector<vector<int>> sticker(2, vector<int>(N, 0)), memo(2, vector<int>(N, 0));
        for(int i=0;i<N;i++) cin >> sticker[0][i];
        for(int i=0;i<N;i++) cin >> sticker[1][i];

        memo[0][0] = sticker[0][0];
        memo[1][0] = sticker[1][0];
        memo[0][1] = sticker[0][1] + memo[1][0];
        memo[1][1] = sticker[1][1] + memo[0][0];

        // memo[x][y] 는 sticker[x][y]를 선택했을 때의 max cost 

        for(int i=2;i<N;i++) {
            memo[0][i] = sticker[0][i] + max(memo[1][i-1], memo[1][i-2]);
            memo[1][i] = sticker[1][i] + max(memo[0][i-1], memo[0][i-2]);
        }

        cout << max(memo[0][N-1], memo[1][N-1]) << '\n';
    }
}