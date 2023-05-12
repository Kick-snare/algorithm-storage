#include<bits/stdc++.h>
using namespace std;

int dx[4] {0, 1, 0, -1}; int dy[4] {-1, 0, 1, 0};
int N, M;
bool isIn(int y, int x) { return 0<=x && x<M && 0<=y && y<N; }

int solution(vector<vector<int>> maps)
{
    N = maps.size();
    M = maps[0].size();

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[0][0] = true;
    
    int minPath = 0;
    
    while(!q.empty()) {
        auto [dist, cy, cx] = q.front();
        q.pop();
        
        if(cy == N-1 && cx == M-1) {
            minPath = dist;
            break;
        }        
        
        for(int i=0;i<4;i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if(!isIn(ny, nx)) continue;
            if(visited[ny][nx] == true) continue;
            if(maps[ny][nx] == 1) {
                visited[ny][nx] = true;
                q.emplace(dist+1, ny, nx);    
            }

        }
    }

    
    return minPath ? minPath+1 : -1;
}