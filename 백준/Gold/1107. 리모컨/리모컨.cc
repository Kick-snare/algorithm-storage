#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, tmp;
bool dig[10] = {false,};

int press(int num) {
    if(num == 0) return dig[0] ? 0 : 1;

    int len = 0;
    while(num > 0){
        if(dig[num%10]) return 0;
        len++;
        num/=10;
    }
    return len;
}

int main() {
    
    cin >> N >> tmp;
    while(cin >> tmp) dig[tmp] = true;

    int result = abs(N - 100);
    for(int i=0;i<1000000;i++){
        int ans;
        if(press(i)) ans = press(i) + abs(N-i);
        else ans = abs(100-N);
        result = min(result, ans);
    }
    cout << result;

}