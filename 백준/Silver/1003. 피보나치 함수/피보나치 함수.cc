#include <iostream>
using namespace std;

int zero_cnt,one_cnt = 0;
int fibo_arr[41][2] = {0,};

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N,tmp;
    
    cin >> N;

    fibo_arr[0][1] = fibo_arr[1][0] = 0;
    fibo_arr[0][0] = fibo_arr[1][1] = 1;


    for(int i=2;i<=40;i++){
        fibo_arr[i][0] = fibo_arr[i-1][0] + fibo_arr[i-2][0];
        fibo_arr[i][1] = fibo_arr[i-1][1] + fibo_arr[i-2][1];
    }

    for(int i=0;i<N;i++){
        cin >> tmp;
        cout << fibo_arr[tmp][0] <<  " " << fibo_arr[tmp][1] << "\n";
    }

    return 0;
}