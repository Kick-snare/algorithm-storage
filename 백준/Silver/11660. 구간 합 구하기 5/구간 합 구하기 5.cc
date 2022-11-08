#include <bits/stdc++.h>
using namespace std;
int table[1025][1025], memo[1025][1025], query[100001][4];

int getSum(int x, int y) {
    if(memo[x][y]) return memo[x][y];
    int sum = table[x][y];

    if(x!=1) sum += getSum(x-1, y);
    if(y!=1) sum += getSum(x, y-1);
    if(x!=1 && y!=1) sum -= getSum(x-1, y-1);

    memo[x][y] = sum;
    return sum;
}

int getSecSum(int x1, int y1, int x2, int y2) {
    int result = getSum(x2, y2);
    if(x1!=1) result -= getSum(x1-1, y2);
    if(y1!=1) result -= getSum(x2, y1-1);
    if(x1!=1 && y1!=1) result += getSum(x1-1, y1-1);
    return result;
}

int main() {
    int N, M, n;
    cin >> N >> M;

    for(int i=1;i<=N;i++) for(int j=1;j<=N;j++) cin >> table[i][j];
    for(int i=0;i<M;i++) for(int j=0;j<4;j++) cin >> query[i][j];

    for(int i=0;i<M;i++)
        cout << getSecSum(query[i][0], query[i][1], query[i][2], query[i][3]) << '\n';
}