#include<bits/stdc++.h>
using namespace std;
int M, N, x, y, day=0;
vector<vector<int>> arr(1001, vector<int>(1001, 0));
queue<pair<int, int>> q;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

bool IsInside(int i, int j) {
    return (0 <= j && 0 <= i && j < M && i < N);
}

int main() {
    // 가로 세로
    cin >> M >> N;

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1) q.push({i, j});
        }

    while(!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (IsInside(ny,nx) && arr[ny][nx] == 0) {
                arr[ny][nx] = arr[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }

    for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if (arr[i][j] == 0) { 
                printf("-1\n");
                return 0;
            }

            if (day < arr[i][j]) {
                day = arr[i][j];
            }
        }
    }
    printf("%d\n", day-1);
}