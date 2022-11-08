#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int min_diff = 2000000000;
int result[2];

void getMinDiff(int left, int right) {
    if(left >= right) return;
    int diff = arr[left] + arr[right];

    if(min_diff > abs(diff)){
        min_diff = abs(diff);
        result[0] = left;
        result[1] = right;
        // cout << arr[result[0]] << ' ' << arr[result[1]] << '\n';
    }
    if(diff > 0)
        getMinDiff(left, right-1);
    else if (diff < 0)
        getMinDiff(left+1, right);
    else return;
}

int main(){
    int N, tmp;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> tmp;
        arr.push_back(tmp); 
    }
    sort(arr.begin(), arr.end());

    // for(auto i:arr) cout << i << " "; cout << endl;

    getMinDiff(0, arr.size()-1);
    cout << arr[result[0]] << " " << arr[result[1]];
}