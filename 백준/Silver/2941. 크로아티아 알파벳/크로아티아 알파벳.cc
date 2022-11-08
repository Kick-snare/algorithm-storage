#include <bits/stdc++.h>
using namespace std;
int main(){
    int cnt=0;
    string str;
    cin >> str;
    str += "00";
    for(int i=0;i<str.size()-2;i++){
        if((str[i]=='l' || str[i]=='n') && str[i+1] == 'j' 
        || (str[i]=='c' || str[i]=='s' || str[i]=='z') && str[i+1] == '='
        || (str[i]=='c' || str[i]=='d') && str[i+1] == '-') i++;
        else if(str[i]=='d' && str[i+1] == 'z' && str[i+2] == '=') i+=2;
        cnt++;
    }
    cout << cnt;
}