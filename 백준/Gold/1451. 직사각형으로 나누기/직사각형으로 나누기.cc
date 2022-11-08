#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;

int N,M;
char arr[101][101];
ll result=0, sum[101][101]={0,};

ll get_sum(int start_x, int start_y, int end_x, int end_y){
    return sum[end_y-1][end_x-1] - sum[end_y-1][start_x-1] - sum[start_y-1][end_x-1] + sum[start_y-1][start_x-1];
}

int main(){
    char tmp;
    cin >> M >> N;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin >> arr[i][j]; 

    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
			sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (arr[i][j]-'0');


    for(int i=1;i<M;i++)
        for(int j=1;j<N;j++){
            ll A,B,C,D;
            A = get_sum(0,0,j,i);
            B = get_sum(j,0,N,i);
            C = get_sum(0,i,j,M);
            D = get_sum(j,i,N,M);

            result = max(result, (A+B)*C*D);
            result = max(result, (A+C)*B*D);
            result = max(result, (C+D)*A*B);
            result = max(result, (B+D)*A*C);
        }

    if(M>2) for(int i=1;i<M-1;i++) 
        for(int j=i+1;j<M;j++)
            result = max(result, get_sum(0,0,N,i) * get_sum(0,i,N,j) * get_sum(0,j,N,M));
    if(N>2) for(int i=1;i<N-1;i++) 
        for(int j=i+1;j<N;j++)
            result = max(result, get_sum(0,0,i,M) * get_sum(i,0,j,M) * get_sum(j,0,N,M));

    cout << result;
}