#include <iostream>
using namespace std;

int N, S, result=0, arr[20];

void f(int idx,int sum){
    sum+=arr[idx];
    if(idx>=N) return;
    if(sum == S) result++;
    f(idx+1,sum-arr[idx]);
    f(idx+1,sum);
    return;
}

int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> arr[i];
    f(0,0);
    cout << result;
}