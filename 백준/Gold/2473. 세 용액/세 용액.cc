#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

long long N, arr[5002], result[3], min_val=LLONG_MAX;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr,arr+N);
    
    for(int i=0;i<N-2;i++){
        int left = i+1, right = N-1;

        while(left<right){
            long long sum = arr[i] + arr[left] + arr[right];

            if(min_val > abs(sum)) {
                min_val = abs(sum);
                result[0] = arr[i];
                result[1] = arr[left];
                result[2] = arr[right];
            }

            if(sum < 0) left++;
            else if(sum > 0) right--;
            else {
                i=N;
                break;
            }
        }
    }

    cout << result[0] << ' ' << result[1] << ' ' << result[2] << '\n';
}