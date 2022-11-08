#include <bits/stdc++.h>
using namespace std;
int N, L, H, R;
using tiib = tuple<int, int, bool>;
vector<tiib> points;

int main() {
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> L >> H >> R;
        points.emplace_back(L, H, true);
        points.emplace_back(R, H, false);
    }

    sort(points.begin(), points.end(), [](auto &p1, auto &p2) {
        if(get<0>(p1) == get<0>(p2)) return get<2>(p1);
        return p1 < p2;
    });

    int x, h, start, last_h = 0;
    multiset<int, greater<int>> ms;
    ms.insert(0);

    // for(auto &s : points) {
    //     tie(x, h, start) = s;
    //     cout << x << ' ' << h <<  ' ' << start <<endl;
    // } cout << endl;

    for(auto &point : points) {
        tie(x, h, start) = point;
        
        if(start) ms.insert(h);
        else {
            auto itr = ms.find(h);
            if(itr != ms.end()) ms.erase(itr);
        }
        // cout << x << ' ' << h <<  ' ' << start <<endl;
        // for(auto &s : ms) cout << s << ' '; cout << endl << endl;
        
        if(last_h != *ms.begin()) cout << x << ' ' << *ms.begin() << ' ';
        last_h = *ms.begin();
    }
}