#include <bits/stdc++.h>
using namespace std;
int N, M, num;
set<int> cards;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    while(N-- && cin >> num) cards.emplace(num);
    cin >> M;
    while(M-- && cin >> num) {
        auto itr = cards.find(num);
        if(itr != cards.end()) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
}