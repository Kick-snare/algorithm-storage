#include <bits/stdc++.h>
using namespace std;

int N, zari[21][21];
int dx[4] {0, 1, 0, -1}, dy[4] {-1, 0, 1, 0};
vector<pair<int, vector<int>>> affinities;

bool isIn(int y, int x) { return 0 <= x && x < N && 0 <= y && y < N; }

int main() {
    cin >> N;
    int student, input[4];
    while(cin >> student) {
        for(int i=1;i<=4;i++) cin >> input[i];
        affinities.emplace_back(student, vector<int>(input, input+5));
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            zari[i][j] = -1;
        }
    } 

    bool condition1 = false;

    for(auto &affinity : affinities) {

    //     for(int i=0;i<N;i++) {
    //     for(int j=0;j<N;j++) {
    //         cout << zari[i][j] << ' ';
    //     }
    //     cout << endl;
    // } cout << endl;

        auto [student, want] = affinity;
        map<int, vector<pair<int, int>>, greater<int>> wantMap;
        map<int, vector<pair<int, int>>, greater<int>> blankMap;

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(zari[i][j] != -1) continue;

                int want_sum = 0, blank_cnt = 0;
                
                for(int d=0;d<4;d++) {
                    int nx = dx[d]+j, ny = dy[d]+i;
                    
                    if(
                        isIn(nx, ny) &&
                        find(want.begin(), want.end(), zari[ny][nx]) != want.end()
                    )
                        want_sum++;
                }

                wantMap[want_sum].emplace_back(i, j);
            }
        }


        if(wantMap.begin()->second.size() == 1) {
            int y, x;
            tie(y, x) = wantMap.begin()->second.front();
            zari[y][x] = student;
            // cout << "(1) " << y << ' ' << x << ", student : " << student << endl;
            continue;
        }

        for(auto p: wantMap.begin()->second) {
            auto [yy, xx] = p;
            if(zari[yy][xx] != -1) continue;

            int blank_cnt = 0;
            
            for(int d=0;d<4;d++) {
                int nx = dx[d]+xx, ny = dy[d]+yy;

                // 빈자리
                if(isIn(nx, ny) && zari[ny][nx] == -1) {
                    blank_cnt++;
                }
            }
            blankMap[blank_cnt].emplace_back(yy, xx);
        }
        
        if(blankMap.begin()->second.size() == 1) {
            int y, x;
            tie(y, x) = blankMap.begin()->second.front();
            zari[y][x] = student;
            // cout << "(2) " << y << ' ' << x << ", student : " << student << endl;
            continue;
        }

        vector<pair<int, int>> last = blankMap.begin()->second;
        sort(last.begin(), last.end());
        zari[last.front().first][last.front().second] = student;
        // cout << "(3) " << last.front().first << ' ' << last.front().second << ", student : " << student << endl;
    }

    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<N;j++) {
    //         cout << zari[i][j] << ' ';
    //     }
    //     cout << endl;
    // } cout << endl;


    map<int, vector<int>> affMap;
    for(auto &affinity : affinities) {
        affMap[affinity.first] = affinity.second;
    }

    int answer = 0;

    for(int i =0;i<N;i++) {
        for(int j=0;j<N;j++) {
            vector<int> wantList = affMap[zari[i][j]];
            int want_sum = 0;

            for(int d=0;d<4;d++) {
                int nx = dx[d]+j, ny = dy[d]+i;

                if(
                    isIn(nx, ny) &&
                    find(wantList.begin(), wantList.end(), zari[ny][nx]) != wantList.end()
                ) want_sum++;
            }

            if(want_sum == 4) answer += 1000;
            else if(want_sum == 3) answer += 100;
            else if(want_sum == 2) answer += 10;
            else if(want_sum == 1) answer += 1;
        }
    }
    cout << answer;
    return 0;
}