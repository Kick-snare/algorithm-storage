#include <bits/stdc++.h>

using namespace std;


int dfs(
    vector<int> &numbers,
    int idx,
    int sum,
    int target
) {

    if(idx == numbers.size())
        return sum == target ? 1 : 0;
    
    int _sum = 0;

    _sum += dfs(numbers, idx+1, sum+numbers[idx], target);
    _sum += dfs(numbers, idx+1, sum-numbers[idx], target);
    
    return _sum;
}

int solution(vector<int> numbers, int target) {
    
    return dfs(numbers, 0, 0, target);
}