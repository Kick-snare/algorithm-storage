#include <bits/stdc++.h>
using namespace std;
string answer = "";

void toUpper(string& str) {
    for(auto &c : str)
        if(65 <= c && c <= 90) c += 'a'-'A';
}

void removeSpecial(string& str) {
    string newstr = "";
    for(auto &c : str)
        if(97 <= c && c <= 122 ||
           '0' <= c && c <= '9' ||
           c == '_' || c == '-' || c == '.'
          ) 
            newstr += c;
    str = newstr;
}

void removeRedundent(string &str) {
    string newstr = "#";
    
    for(int i=0;i<str.length();i++) {
        if(str[i] != '.' || str[i] != newstr.back()) newstr += str[i];
    }
           
    str = newstr.substr(1, newstr.length()-1);
}

void trimMargin(string &str) {
    if(str[0] == '.') str.erase(str.begin());
    if(str.back() == '.') str.pop_back();
}

void inserta(string &str) {
    if(str.empty()) str = "a";
}

void trim15(string &str) {
    if(str.length() > 15) str = str.substr(0, 15);
    if(str.back() == '.') str.pop_back();
}

void under2(string &str) {
    if(str.length() == 2) str += str.back();
    if(str.length() == 1) str += string{str.back()} + string{str.back()};
}

string solution(string str) {
    
    toUpper(str);
    // cout << str << endl;
    
    removeSpecial(str);
    // cout << str << endl;
    
    removeRedundent(str);
    // cout << str << endl;
        
    trimMargin(str);
    // cout << str << endl;
    
    inserta(str);
    // cout << str << endl;
        
    trim15(str);
    // cout << str << endl;
    
    under2(str);
    // cout << str << endl;
    
    return str;
}