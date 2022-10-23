#include <bits/stdc++.h>
using namespace std;
int N, K, L, x, y, z;
typedef pair<int, int> pii;
set<pii> apples;
priority_queue<pii> direction;
vector<vector<int>> board(101, vector<int>(101, 0));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isIn(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < N;
}

int main() {

    cin >> N >> K;
    for(int i=0;i<K;i++) {
        cin >> y >> x;
        apples.insert({x-1, y-1});
    }

    char c;
    cin >> L;
    for(int i=0;i<L;i++) {
        cin >> z >> c;
        direction.push({-z, c == 'D'});
    }

    int t=0, d=0, x=0, y=0;
    int len = 1;

    while(isIn(x, y)) {
        
        // cout << "t, x, y : " << t << ' ' << x << ' ' << y << endl;
        

        auto apple = apples.find({x, y});
        if(apple != apples.end()) {
            apples.erase(apple);
            len++;
            // cout << "apple! " << len << endl;
        }


        if(board[y][x] != 0 && t-len <= board[y][x]) break;

        board[y][x] = t;
        t++;


        if(!direction.empty() && -direction.top().first == t-1) {
            if(direction.top().second) d++;
            else d += 3;
            d %= 4;
            direction.pop();
        }

        x = x + dx[d];
        y = y + dy[d];
    }

    cout << t;
                        
}