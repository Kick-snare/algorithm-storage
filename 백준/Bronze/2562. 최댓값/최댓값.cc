#include <iostream>
using namespace std;

int main(){
    int a[9],max = 0;
    for(int i=0;i<9;i++) cin >> a[i];
    for(int i=1;i<9;i++) max = a[max] > a[i] ? max : i;
    cout << a[max] << "\n" << max+1;
}