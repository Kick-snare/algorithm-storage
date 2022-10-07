#include <bits/stdc++.h>
using namespace std;
int N, M, answer = INT_MAX;
vector<vector<bool>> wall;
int visited[1001][1001][2];

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool isIn(int i, int j) {return 0 <= i && i < N && 0 <= j && j < M;}

void bfs() {
    int i, j, punch;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 1});
    visited[0][0][0] = 1;

    while(!q.empty()) {
        tie(i, j, punch) = q.front();
        q.pop();

        if(i == N-1 && j == M-1) {
            answer = visited[i][j][punch];
            return;
        }

        // 상하좌우 탐방
        for(int k=0;k<4;k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            
            // 범위 밖이거나, 이미 방문 했거나
            if(!isIn(x, y)) continue;

            // 벽이 있고 부수거나
            if(wall[x][y] && punch) {
                visited[x][y][punch-1] = visited[i][j][punch] + 1;
                q.push({x, y, false});
            }

            // 벽이 없거나
            else if(!wall[x][y] && !visited[x][y][punch]) {
                visited[x][y][punch] = visited[i][j][punch] + 1;
                q.push({x, y, punch});
            }
        }
    }
}

int main() {
    string str;
    cin >> N >> M;
    wall.assign(N, vector<bool>(M, 0));

    for(int i=0;i<N;i++) {
        cin >> str;
        for(int j=0;j<M;j++)
            if(str[j] == '1') wall[i][j] = true;
    }

    bfs();

    if(answer == INT_MAX) cout << "-1";
    else cout << answer+1;
}