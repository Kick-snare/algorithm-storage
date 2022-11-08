#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;
    int N, x;
    cin >> N;
    while(N-- && cin >> x)
        if(x) pq.push(x);
        else
            if(pq.empty()) cout << "0\n"; 
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
}