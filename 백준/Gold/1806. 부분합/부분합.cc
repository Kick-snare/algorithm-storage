#include <bits/stdc++.h>
using namespace std;
int N, S, A[100001];

int main() {
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> A[i];

    int l = 0, r = 0, cnt = 0, sum = 0;
    int answer = N+1;
    while(1) {
        
        if(sum >= S) {
            answer = min(answer, r-l);
            sum -= A[l++];
        }
        else if(r > N) break;
        else sum += A[r++];
    }
    if(answer == N+1) cout << "0";
    else cout << answer;
}