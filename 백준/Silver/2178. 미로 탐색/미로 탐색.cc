#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    string str;
    cin >> N >> M;
    vector<vector<bool>> arr;

    while(cin >> str) {
        vector<bool> tmp;
        for(auto &c : str) tmp.push_back(c-'0');
        arr.push_back(tmp);
    }

    queue<tuple<int, int, int>> q; // x, y, time
    q.emplace(0, 0, 0);
    auto curr = q.front();
    arr[0][0] = false;

    while(!q.empty()) {
        curr = q.front();
        if(get<0>(curr) == N-1 && get<1>(curr) == M-1) break;
        q.pop(); 

        if(get<0>(curr) > 0 && arr[get<0>(curr)-1][get<1>(curr)]) {
            arr[get<0>(curr)-1][get<1>(curr)] = false;
            q.emplace(get<0>(curr)-1, get<1>(curr), get<2>(curr)+1);
        } 
        if(get<1>(curr) > 0 && arr[get<0>(curr)][get<1>(curr)-1]) {
            arr[get<0>(curr)][get<1>(curr)-1] = false;
            q.emplace(get<0>(curr), get<1>(curr)-1, get<2>(curr)+1);
        }
        if(get<0>(curr) < N-1 && arr[get<0>(curr)+1][get<1>(curr)]) {
            arr[get<0>(curr)+1][get<1>(curr)] = false;
            q.emplace(get<0>(curr)+1, get<1>(curr), get<2>(curr)+1);
        }
        if(get<1>(curr) < M-1 && arr[get<0>(curr)][get<1>(curr)+1]) {
            arr[get<0>(curr)][get<1>(curr)+1] = false;
            q.emplace(get<0>(curr), get<1>(curr)+1, get<2>(curr)+1);
        }

    }
    cout << get<2>(curr) + 1;
}