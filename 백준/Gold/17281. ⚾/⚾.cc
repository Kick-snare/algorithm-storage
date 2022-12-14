#include <bits/stdc++.h>
using namespace std;
int N, maxScore;

int getScore(vector<vector<int>> &arr, list<int> &order) {
    int totalScore = 0;
    auto hitter = order.begin();
    // cout << "[ ";for(auto &w : order) cout << w << ' '; cout << "]\n";

    for(int inning=1;inning<=N;inning++) {
        // queue<bool> bases;
        // for(int i=0;i<3;i++) bases.push(false);
        // for(int j=0;j<result;j++) {
        //     if(j==0) bases.push(true);
        //     else     bases.push(false);
        //     if(bases.front()) score++;
        //     bases.pop();
        // }  Queue로는 풀 수 없다 (느림)

        vector<int> results;
        int sum=0, out=0, score=0;

        while(out < 3) {
            int result = arr[inning][*hitter];

            if(result) results.push_back(result);
            else out++;
            if(++hitter == order.end()) hitter++;
        }
        for(int i=(int)results.size()-1;i>=0;i--) {
            sum += results[i];
            if(sum < 4) continue;
            score += i+1;
            break;
        }

        // cout << endl << "[" << inning << "] score : "<< score << endl;
        totalScore += score;
    }
    // cout << "total : " << totalScore << endl << endl;
    return totalScore;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    vector<vector<int>> arr(N+1, vector<int>(10));
    for(int i=1;i<=N;i++) for(int j=1;j<10;j++) cin >> arr[i][j];
    list<int> order{2,3,4,5,6,7,8,9};

    auto fourth = next(order.begin(), 3);
    do {
        order.insert(fourth, 1);
        maxScore = max(maxScore, getScore(arr, order));
        order.erase(prev(fourth, 1));
    } while(next_permutation(order.begin(), order.end()));

    cout << maxScore;
}