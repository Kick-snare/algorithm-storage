#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int N, tmp, max_idx = 0;
    int pole[501] = {0,}, dp[501] = {0,};

    cin >> N;

    for(int i=0;i<N;i++) {
        cin >> tmp;
        cin >> pole[tmp];
        max_idx = max(max_idx, tmp);
    }

    for(int i=0;i<max_idx;i++) 
        if(pole[i+1]) dp[i+1] = 1;

    for(int i=1;i<=max_idx;i++){

        for(int j=1;j<i;j++){

            if (pole[i] > pole[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << N - *max_element(dp,dp+501);
    

    return 0;
}