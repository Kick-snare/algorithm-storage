#include <iostream>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int digits[10]={0,}, mul = A*B*C;
    while(mul){
        digits[mul%10]++;
        mul/=10;
    }
    for(int i=0;i<10;i++) cout << digits[i] << '\n';
}