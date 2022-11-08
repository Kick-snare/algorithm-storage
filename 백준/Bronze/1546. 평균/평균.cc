#include <iostream>
using namespace std;

int main(){
    int N,max=0;
    double score[1000], sum=0;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> score[i];
        max = max < score[i] ? score[i] : max;
    }
    for(int i=0;i<N;i++) sum += (score[i]/max)*100;

    sum /= N;
    cout << sum;
}