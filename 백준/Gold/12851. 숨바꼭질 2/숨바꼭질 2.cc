#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> q;
    bool visited[100002] = {false,};
    visited[N] = true;
     q.push({N, 0});
    int best = 0, count = 0;

    while(!q.empty()) {
        int curr = q.front().first;
        int time = q.front().second;
        // cout << time << ' ' << curr << endl;
        if(best && time > best) break;
        if(curr == K && !best) best = time;
        if(best && curr==K) count++;

        q.pop();
        visited[curr] = true;

        if(curr > 0 && !visited[curr-1]) q.push({curr-1, time+1});
        if(curr < 100001 && !visited[curr+1]) q.push({curr+1, time+1});
        if(curr*2 < 100001 && !visited[curr*2]) q.push({curr*2, time+1});
    }
    if(!best) count++;
    cout << best << '\n' << count;
}