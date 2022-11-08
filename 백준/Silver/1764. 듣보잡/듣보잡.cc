#include <bits/stdc++.h>
using namespace std;
int N, M;
set<string> n1, n2;

int main() {
    cin >> N >> M;
    string name;
    vector<string> result;
    while(N-- && cin >> name) n1.emplace(name);
    while(M-- && cin >> name) n2.emplace(name);

    set_intersection(n1.begin(), n1.end(), n2.begin(), n2.end(), back_inserter(result));

    cout << result.size() << '\n';
    for(auto &str : result) cout << str << '\n';

}