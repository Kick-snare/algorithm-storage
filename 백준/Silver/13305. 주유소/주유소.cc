#include <iostream>
using namespace std;

int main(){
    int N;
    int city[100000],stlen[100000];
    
    cin >> N;
    for(int i=0;i<N-1;i++) cin >> stlen[i];
    for(int i=0;i<N;i++) cin >> city[i];

    int cost = 0, min_val = city[0];
    for(int i=0;i<N-1;i++){
        if(min_val >= city[i]) min_val = city[i];
        cost += min_val * stlen[i];
    }

    cout << cost;
    return 0;
}