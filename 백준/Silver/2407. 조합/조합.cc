#include <bits/stdc++.h>
using namespace std;
int N, M;
string f[101][101];

string addBigNum(string n1, string n2) {
    int sum = 0 ;
    string result;

    while(!n1.empty() || !n2.empty() || sum) {
        if(!n1.empty()) {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if(!n2.empty()) {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum%10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int m) {
    if(n == m || m == 0) return "1";
    string &result = f[n][m];
    if(result!="") return result;
    result = addBigNum(combination(n-1, m-1), combination(n-1, m));
    return result;
}


int main() {
    cin >> N >> M;
    
    cout << combination(N, M);
}