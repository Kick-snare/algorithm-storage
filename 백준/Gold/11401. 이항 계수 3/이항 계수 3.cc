#include <iostream>
using namespace std;

const long long MOD = 1000000007LL;
int N, K;

long long pow(long long a, long long b){
    if(b == 0) return 1;
    if(b % 2) return (pow(a, b-1) * a) % MOD;
    long long half = pow(a, b / 2) % MOD;
    return (half * half) % MOD;
}

int main(){
    cin >> N >> K;
    long long A=1,B=1;
    for(int i=N-K+1;i<=N;i++){
        A *= i;
        A %= MOD;
    }
    for(int i=1;i<=K;i++){
        B *= i;
        B %= MOD;
    }
    B = pow(B, MOD-2);
    long long ans = (A * B) % MOD;
    cout << ans;
    return 0;
}