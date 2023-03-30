#include <bits/stdc++.h>
using namespace std;

queue<int> bridge;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    for(int i=0;i<bridge_length;i++) 
        bridge.push(0);
    
    int weight_sum = 0, index = 0, time = 0, passed_truck_count = 0;
    
    while(passed_truck_count != truck_weights.size()) {
        if(bridge.front() != 0) {
            weight_sum -= bridge.front();
            passed_truck_count++;
        }
        bridge.pop();

        
        int surplus = weight - weight_sum;
        
        // cout << "time: " << time << ", " << surplus << ", " << bridge.front() << endl;
        
        if(surplus >= truck_weights[index]) {
            bridge.push(truck_weights[index++]);
            weight_sum += bridge.back();
        } else {
            bridge.push(0);
        }
        
        time++;

        
    }
    
    return time;
}