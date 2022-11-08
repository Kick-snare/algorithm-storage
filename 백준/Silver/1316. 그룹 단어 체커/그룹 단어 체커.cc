#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, cnt = 0;
    bool apb[26];
    string tmp;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> tmp;
        fill_n(apb,26,0);
        char forward = 'A';
        for(auto i : tmp){
            if(forward == i) continue;
            forward = i;
            if(apb[i-'a']) {
                cnt++;
                break;
            }
            else apb[i-'a']=true;
        }
    }
    cout << N - cnt;

}