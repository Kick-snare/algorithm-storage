#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int tmp, n, bowl[500000] = {0,};
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        bowl[tmp-1]++;
    }

    cout << *max_element(bowl,bowl+500000);
    return 0;
}