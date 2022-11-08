#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, S=0, inp; string cmd;
    cin >> N;

    while(N-- && cin >> cmd) {
        if(cmd[0] == 'a' && cmd[1] == 'd' && cin >> inp)
            S |= (1<<inp);

        else if(cmd[0] == 'r' && cin >> inp) {
            if(S & (1 << inp)) S &= ~(1<<inp);
        }
        else if(cmd[0] == 'c' && cin >> inp)
            if(S & (1 << inp)) cout << "1\n";
            else cout << "0\n";
    
        else if(cmd[0] == 't' && cin >> inp) S ^= (1<<inp);
        else if(cmd[0] == 'a') S = (1 << 21) - 1;
        else if(cmd[0] == 'e') S = 0;
    }
}