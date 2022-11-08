#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, num, maxWeight = 0;
    cin >> N;
    multiset<int> nums;
    int rope = N;
    while(N-- && cin >> num) nums.insert(num);
    for(auto &num : nums) {
        // cout << num * rope << endl;
        maxWeight = max(maxWeight, num * rope--);
    }
    cout << maxWeight;
}