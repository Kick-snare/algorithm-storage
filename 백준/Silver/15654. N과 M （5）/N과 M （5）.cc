#include <bits/stdc++.h>
using namespace std;
int N, M, n;
vector<int> nums;

void permutation(int depth, vector<bool> &visited, vector<int> select) {
    if(depth == M) {
        for(auto &w : select) cout << w << ' ';
        cout << '\n';
        return;
    }

    for(int i=0;i<nums.size();i++){
        if(visited[i]) continue;
        visited[i] = true;
        select.push_back(nums[i]);
        permutation(depth+1, visited, select);
        visited[i] = false;
        select.pop_back();
    }
}

int main() {
    cin >> N >> M;
    vector<bool> visited(N, false);
    while(cin >> n) nums.push_back(n);
    sort(nums.begin(), nums.end());
    permutation(0, visited, vector<int>());
}