#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int N, num, mid = 0;
    cin >> N >> mid;
    cout << mid << '\n';
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    while(cin >> num) {
        if(num >= mid) right.push(num);
        else left.push(num);

        if(left.size()+1 < right.size()) {
            left.push(mid);
            if(right.empty()) continue;
            mid = right.top();
            right.pop();
        } else if(left.size() > right.size()) {
            right.push(mid);
            if(left.empty()) continue;
            mid = left.top();
            left.pop();
        }
        cout << mid << '\n';
    }
}