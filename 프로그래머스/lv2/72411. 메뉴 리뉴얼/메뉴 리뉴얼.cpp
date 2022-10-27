#include<bits/stdc++.h>
using namespace std;

void bt(int index, string select, string &order, set<string> &comb) {
    if(select.length() >= 2) {
        comb.insert(select);
        if(select.length() == order.length()) return;
    } 
    
    for(int i=index;i<order.length();i++)
        bt(i+1, select+string{order[i]}, order, comb);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    map<string, int> setCount;
    
    for(auto &order : orders) {
        set<string> comb;
        sort(order.begin(), order.end());
        bt(0, "", order, comb);
        for(auto &str : comb) setCount[str]++;
    }
    
    vector<pair<string, int>> sets(setCount.begin(), setCount.end());
    
    sort(sets.begin(), sets.end(), [](auto &a, auto &b){
        if(a.first.length() != b.first.length()) return a.first.length() < b.first.length();
        return a.second > b.second;
    });
    
    // for(auto &p: sets) cout << p.first << ' ' << p.second << endl;
    
    vector<string> answer;
    int idx = 0;
    sets.push_back({"endofline1234567", 0});
    
    for(int i=0;i<sets.size();) {
        int currLen = sets[i].first.length();
        int maxcount = sets[i].second;
        
        if(find(course.begin(), course.end(), currLen) == course.end()) {
            i++;
            continue;
        }
        
        while(maxcount == sets[i].second) {
            if(maxcount > 1) answer.push_back(sets[i].first);
            i++;
        }
            
        
        
        if(i >= sets.size()-1) break;

        while(currLen == sets[++i].first.length());
        
        if(i >= sets.size()-1) break;  
    }

    sort(answer.begin(), answer.end());
    return answer;
}