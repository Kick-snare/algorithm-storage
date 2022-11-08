#include <bits/stdc++.h>
using namespace std;
int N;
int geo[101][101];

int getArea(int height) {
    vector<vector<bool>> flooded(N+1, vector<bool>(N+1, false));
    for(int i=0;i<N;i++) for(int j=0;j<N;j++)
        if(geo[i][j] < height) flooded[i][j] = true;
    
    int cntArea = 0;
    for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
        if(flooded[i][j]) continue;
        cntArea++;
        queue<pair<int, int>> q;
        q.emplace(i, j);
        flooded[i][j] = true;
        
        while(!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if(x!=0 && !flooded[x-1][y]) {
                q.emplace(x-1, y);
                flooded[x-1][y] = true;
            }
            if(y!=0 && !flooded[x][y-1]) {
                q.emplace(x, y-1);
                flooded[x][y-1] = true;
            }
            if(x!=N-1 && !flooded[x+1][y]) {
                q.emplace(x+1, y);
                flooded[x+1][y] = true;
            }
            if(y!=N-1 && !flooded[x][y+1]) {
                q.emplace(x, y+1);
                flooded[x][y+1] = true;
            }
        }
    }
    return cntArea;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++) 
        for(int j=0;j<N;j++) cin >> geo[i][j];

    int maxArea = 0;
    for(int height=1; height<=100; height++) {
        int area = getArea(height);
        if(area == 0) break;
        maxArea = max(maxArea, area);
    }

    cout << maxArea;
}