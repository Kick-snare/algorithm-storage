#include <iostream>
using namespace std;

int main(){
    int tmp, mod[42]={0,};
    for(int i=0;i<10;i++){
        cin >> tmp;
        mod[tmp%42]++;
    }
    int sum=0;
    for(int i=0;i<42;i++) if(mod[i]) sum++;
    cout << sum;
}