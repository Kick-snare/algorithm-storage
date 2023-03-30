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
            answer[top_time-1] = i + 1 - top_time;
            st.pop();
        }
        st.emplace(prices[i], i+1);
    }
    
    while(!st.empty()) {
        auto [top_price, top_time] = st.top();
        if(top_price == -1) break;
        answer[top_time-1] = prices.size() - top_time;
        st.pop();
    }
    
    return answer;
}