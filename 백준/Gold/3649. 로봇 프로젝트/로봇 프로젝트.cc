#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(false);cin.tie(NULL);
    int x,n, lego[1000000];
    while(true){
        if(!(cin >> x)) break;
        x *= 10000000;
        cin >> n;
        for(int i=0;i<n;i++) cin >> lego[i];
        sort(lego,lego+n);
        
        int sum=0, left=0, right=n-1;
        bool flag = true;
        while(left<right){
            sum = lego[left] + lego[right];
            if(sum < x) left++;
            else if(sum > x) right--;
            else {
                flag = false;
                break;
            }
        }

        if(flag) cout << "danger\n";
        else cout << "yes " << lego[left] << ' ' << lego[right] << "\n";
    }
    return 0;
}