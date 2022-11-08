#include <iostream>
using namespace std;

int main(){
    int c, n, arr[1000];
    cin >> c;
    while(c--){
        cin >> n;
        double sum=0;
        for(int i=0;i<n;i++){
            cin >> arr[i]; 
            sum += arr[i];
        }
        sum/=n;
        double cnt=0;
        for(int i=0;i<n;i++) if(arr[i]>sum) cnt++;
        cout.precision(3); cout << fixed;
        cout << (cnt/n)*100 << '%' <<'\n';
    }
}