#include <bits/stdc++.h>
using namespace std;
vector<string> users, bans;
set<string> s;


bool isCase(string &user, string &ban) {
    if(user.length() != ban.length()) 
        return false;
    
    for(int i=0;i<user.length();i++) 
        if(user[i] != ban[i] && ban[i] != '*') 
            return false;
    
    return true;
}

void bt(vector<int> &visited, int idx) {

    if(idx == bans.size()) {
        string str = "";
        
        for(int i=0;i<users.size();i++) 
            if(visited[i]) 
                str += users[i];
        s.insert(str);

        return;
    }
    
    for(int i=0;i<users.size();i++) {
        if(isCase(users[i], bans[idx]) && !visited[i]) {

            visited[i] = true;
            bt(visited, idx+1);
            visited[i] = false;
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    users = user_id;
    bans  = banned_id;
    
    vector<int> arr(8, false);
    bt(arr, 0);

    return s.size();
}