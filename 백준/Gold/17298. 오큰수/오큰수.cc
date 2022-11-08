#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N, tmp, arr[1000000];
    stack< pair<int, int> > stk;
    cin >> N;
    fill_n(arr,N,-1);
    for(int i=0;i<N;i++) {
        cin >> tmp;
        if(!i) stk.push({i, tmp});
        else
            while(!stk.empty() && stk.top().second < tmp){
                arr[stk.top().first] = tmp;
                stk.pop();
            }
        stk.push({i, tmp});
    }
    for(int i=0;i<N;i++) cout << arr[i] << " "; 
    return 0;
}
