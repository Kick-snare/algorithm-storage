#include <iostream>
using namespace std;

int main(){
    int n,tmp,min=1000000,max=-1000000;
    cin >> n;
    while(n--) {
        cin >> tmp;
        max = max < tmp ? tmp : max;
        min = min > tmp ? tmp : min;
    }
    cout << min << ' ' << max;
}