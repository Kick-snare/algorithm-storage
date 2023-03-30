#include <bits/stdc++.h>
using namespace std;

stack<pair<int, int>> st; // price, time

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    int time = 0;
    st.emplace(-1, 0);
    
    for(int i=0;i<(int) prices.size();i++) {
        
        while(st.top().first > prices[i]) {
            auto [top_price, top_time] = st.top();

            if(top_price > prices[i]) {
                // cout << "pop : " << top_price << " " << i-top_time+1 << endl;
                answer[top_time-1] = i + 1 - top_time;
                st.pop();
            }   
        }
        
        // cout << "push : " << prices[i] << " " << i+1 << endl;
        st.emplace(prices[i], i+1);
    }
    // cout << endl;
    
    while(!st.empty()) {
        auto [top_price, top_time] = st.top();
        if(top_price == -1) break;
        // cout << "pop : " << top_price << " " << top_time << endl;
        answer[top_time-1] = prices.size() - top_time;
        st.pop();
    }
    
    
    return answer;
}