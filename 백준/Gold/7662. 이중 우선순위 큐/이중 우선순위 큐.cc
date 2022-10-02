#include<bits/stdc++.h>
using namespace std;
int T, k, oprd;
char optr;

int main() {
    // testcase 갯수 T
    cin >> T;
    
    while(T--) {
        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        map<int, int> mark;

        // operation의 갯수 k
        cin >> k;

        while(k--){

            // 명령어 입력
            cin >> optr >> oprd;

            // delete 명령
            if(optr == 'D') {
                if(oprd > 0) {
                    while(!maxpq.empty() && mark[maxpq.top()] == 0)
                        maxpq.pop();

                    if(!maxpq.empty()) {
                        mark[maxpq.top()]--;
                        maxpq.pop();
                    }
                } 
                else {
                    while(!minpq.empty() && mark[minpq.top()] == 0)
                        minpq.pop();

                    if(!minpq.empty()) {
                        mark[minpq.top()]--;
                        minpq.pop();
                    }
                }    
            }

            // insert 명령
            else {
                maxpq.push(oprd);
                minpq.push(oprd);

                if(mark.find(oprd) != mark.end()) 
                    mark[oprd]++;
                else mark[oprd] = 1;
            }
        } 

        while(!maxpq.empty() && mark[maxpq.top()] == 0) maxpq.pop();
        while(!minpq.empty() && mark[minpq.top()] == 0) minpq.pop();
        
        if(minpq.empty() || maxpq.empty()) cout << "EMPTY\n";
        else cout << maxpq.top() << ' ' << minpq.top() << '\n';
    }
}