#include <bits/stdc++.h>
using namespace std;
int n, m;
char str[21];   
map<string, int> mp1;   
string mp2[100001];    
 
void input(){
    cin >> n;
    cin >> m;
 
    for(int i=0; i<n; i++){
        scanf("%s", str);
        string s = str;
 
        mp1.insert(pair<string, int>(s, i));
        mp2[i] = s;
    }
}
 
void solution(){
 
    for(int i=0; i<m ; i++) {
        scanf("%s", str);
 
        if(isdigit(str[0])) {
            cout << mp2[atoi(str)-1] << "\n";
        }else{
 
            string s = str;
            printf("%d\n", mp1[s] + 1);
        }
 
    }
}
 
int main(void){
    input();
    solution();
    return 0;
}