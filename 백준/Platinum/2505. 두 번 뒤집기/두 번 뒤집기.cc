#include <bits/stdc++.h>
using namespace std;
int N; string front, back;

int checkFromFront(vector<int> arr) {
    int cnt=0, target=0;
    front = "";
    while(target <= N) {
        for(int i=target;i<=N;i++) {
            if(target==arr[target]) break;
            else if(target==arr[i]) {
                cnt++;
                reverse(arr.begin()+target, arr.begin()+(i+1));
                front += to_string(target) + " " + to_string(i) + "\n";
            }
        }
        target++;
    }
    return cnt;
}
int checkFromBack(vector<int> arr) {
    int cnt=0, target=N;
    back = "";
    while(target > 0) {
        for(int i=target;i>0;i--) {
            if(target==arr[target]) break;
            else if(target==arr[i]) {
                cnt++;
                reverse(arr.begin()+i, arr.begin()+(target+1));
                back += to_string(i) + " " + to_string(target) + "\n";
            }
        }
        target--;
    }
    return cnt;
}

string check(vector<int> &arr) {
    string result; int minCount;
    int frontCount = checkFromFront(arr);
    int BackCount = checkFromBack(arr);
    if(frontCount < BackCount) {
        result = front;
        minCount = BackCount;
    } else {
        result = back;
        minCount = frontCount;
    }
    if(minCount < 1) result = "1 1\n" + result;
    if(minCount <= 1) result = "1 1\n" + result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin >> N;
    vector<int> arr(N+1);
    for(int j=1;j<=N;j++) cin >> arr[j];
    cout << check(arr);
}
