#include <bits/stdc++.h>
using namespace std;
int N, n, M, D;

int getScore(vector<int> &archer, vector<vector<int>> board) {
    int score = 0;

    for(int i=N-1;i>=0;i--) { // 몬스터 1 전진
        set<pair<int, int>> lockOn;
        
        for(int a=0;a<M;a++) { // archer 당 한 보드 순회
            if(!archer[a]) continue;
            priority_queue<tuple<int, int, int>> targets; // <거리, x, y>

            for(int y=i;y>=0;y--) for(int x=0;x<M;x++) {
                if(!board[y][x]) continue;
                int distance = abs(a-x) + abs(i-y) + 1;
                if(distance <= D) targets.emplace(-distance, -x, y);
            }

            if(targets.empty()) continue;
            lockOn.emplace(-get<1>(targets.top()), get<2>(targets.top()));
        }
        for(auto &target : lockOn) board[target.second][target.first] = 0;

        score += lockOn.size();
    }
    return score;
}

int main() {
    cin >> N >> M >> D;
    vector<vector<int>> board(N, vector<int>(M, 0));

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) cin >> board[i][j];

    int maxScore = 0;
    vector<int> archer(M, 0);
    archer[M-3] = archer[M-2] = archer[M-1] = 1;

    do {
        maxScore = max(maxScore, getScore(archer, board));
    } while(next_permutation(archer.begin(), archer.end()));

    cout << maxScore;
}




