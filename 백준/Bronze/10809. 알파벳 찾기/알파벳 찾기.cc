#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    for(char i='a';i<='z';i++)
        if(S.find(i)==string::npos) cout << -1 << ' ';
        else cout << S.find(i) << ' ';
}