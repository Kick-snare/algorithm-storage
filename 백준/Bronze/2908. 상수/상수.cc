#include <bits/stdc++.h>
using namespace std;

int main(){
    string A, B;
    cin >> A >> B;
    reverse(A.begin(),A.end()); reverse(B.begin(),B.end());
    stoi(A); stoi(B);
    if(A>B) cout << A;
    else cout << B;
}