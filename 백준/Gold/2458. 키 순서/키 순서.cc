#include<bits/stdc++.h>
using namespace std;
int N, M, a, b;

int main() {
    cin >> N >> M;
    vector<vector<bool>> connected(N+1, vector<bool>(N+1, false));
    
    while(cin >> a >> b) connected[a][b] = true;
    for(int i=1;i<=N;i++) connected[i][i] = true;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            for(int k=1;k<=N;k++)
                if(!connected[j][k])
                  connected[j][k] = connected[j][i] & connected[i][k];


    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++) cout << connected[i][j] << ' ';cout << endl;} cout << endl;
    int count = 0;

    for(int i=1;i<=N;i++) {
        int flag = true;
        for(int j=1;j<=N;j++) {
            if(connected[j][i] | connected[i][j]) continue;
            flag = false;
        }
        if(flag) count++;
    }

    cout << count;

}