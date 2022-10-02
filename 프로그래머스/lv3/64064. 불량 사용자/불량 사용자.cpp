#include <bits/stdc++.h>
using namespace std;
set<string> s;
int cnnt =0;

bool isCase(string &user, string &ban) {
    if(user.length() != ban.length()) return false;
    
    for(int i=0;i<user.length();i++) 
        if(user[i] != ban[i] && ban[i] != '*') return false;
    
    return true;
}

void bt(vector<string> &user_id, vector<string> &banned_id, vector<int> &visited, int ban_idx) {

    if(ban_idx == banned_id.size()) {
        cnnt++;
        string str = "";
        for(int i=0;i<user_id.size();i++) if(visited[i]) str += user_id[i];
        s.insert(str);
        // cout << str << endl;
        return;
    }
    
    for(int i=0;i<user_id.size();i++) {
        if(isCase(user_id[i], banned_id[ban_idx]) && !visited[i]
           // find(path.begin(), path.end(), user_id[i]) == path.end()
          ) {

            // path.push_back(user_id[i]);
            visited[i] = true;
            bt(user_id, banned_id, visited, ban_idx+1);
            visited[i] = false;
            // path.pop_back();
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    map<string, int> cnt;
    
    for(auto &id: banned_id)
        if(cnt.count(id)) cnt[id]++;
        else cnt[id] = 1;
    
    // vector<string> arr;
    vector<int> arr(8, false);
    bt(user_id, banned_id, arr, 0);
    
    for(auto &p: cnt)
        if(p.second > 1) 
            cnnt /= p.second;

    return s.size();
}