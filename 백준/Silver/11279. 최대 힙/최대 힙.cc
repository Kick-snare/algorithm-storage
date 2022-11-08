#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    priority_queue<int> pq;
    int N, num;
    cin >> N;

    while(N-- && cin >> num) {
        if(!num)
            if(pq.empty()) cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        else pq.push(num);
    }
}