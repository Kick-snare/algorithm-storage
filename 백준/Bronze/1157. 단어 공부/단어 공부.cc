#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    transform(s.begin(),s.end(),s.begin(),::toupper);

    int apb[26] = {0,};
    pair<int,int> Max(0,0);
    for(int i=0;i<s.size();i++) apb[s[i]-'A']++;

    for(int i=0;i<26;i++) 
        if(Max.second < apb[i]) {
            Max.first = i;
            Max.second = apb[i];
        }

    bool flag = true;
    for(int i=0;i<26;i++) 
        if(Max.second==apb[i] && Max.first!=i) { 
            cout << '?';
            flag = false;
            break;
        }
    
    if(flag) cout << (char)('A'+Max.first);
}