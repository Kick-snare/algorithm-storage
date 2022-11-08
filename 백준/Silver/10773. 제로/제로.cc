#include <iostream>
#include <stack>
using namespace std;

int main(){
    int K, tmp, sum=0;
    stack <int> s;
    cin >> K;

    for(int i=0;i<K;i++) {
        cin >> tmp;

        if(!tmp) {
            sum-=s.top();
            s.pop();
        } else {
            s.push(tmp);
            sum+=s.top();
        }
    }   
    cout << sum;

    return 0;
}