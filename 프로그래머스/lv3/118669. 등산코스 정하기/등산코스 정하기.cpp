#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> graph;
int mark[50001] = {0,};
int dp[50001];

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    
    int min_intensity = INT_MAX, ans_summit = 0;
    graph.resize(n+1, vector<pair<int, int>>(0));
    
    // input edge data
    for(auto &path: paths) {
        graph[path[0]].push_back({path[1], path[2]});
        graph[path[1]].push_back({path[0], path[2]});
    }
    
    // mark gate & summit position
    for(auto &gate: gates) mark[gate] = -1;
    for(auto &summit: summits) mark[summit] = 1;

    int summit = -1, intensity = 0;
    priority_queue<tuple<int,int>> pq;
    
    for(auto &gate: gates) {
        dp[gate] = -1;
        pq.push({0, -gate});
    }

    while(!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();

        // cout << "cost, node : " << -cost << ' ' << -node << endl;

        intensity = max(intensity, -cost);
        // if(intensity > min_intensity) break;

        if(mark[-node] > 0) {
            if(min_intensity > intensity) {
                summit = -node;
                min_intensity = intensity;
            } 
            else if(min_intensity == intensity && -node < summit) {
                summit = -node;
            }
            continue;
        }

        for(auto &next : graph[-node])
            if(dp[next.first] == 0 || dp[next.first] > max(intensity, next.second)){
                dp[next.first] = max(intensity, next.second);
                // cout << "push -> cost, node : " << dp[next.first] << ' ' << next.first << endl;
                pq.push({-dp[next.first], -next.first});   
            }
    }
    ans_summit = summit;

    
    
    return {ans_summit, min_intensity};
}