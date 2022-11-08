#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> moolen(30);

int get_moolen(){
    moolen[0] = 3;
    for(int i=1;1;i++){
        moolen[i] = 2 * moolen[i-1] + i + 3;
        if(moolen[i] > N) return i;
    }
}

void get_char(int i, int n){
    if(!i){
        if(n==1) cout << 'm';
        else cout << 'o';
        return;
    }
    
    if(moolen[i-1] >= n) get_char(i - 1, n);
    else if(moolen[i-1] + i + 3 < n) get_char(i - 1, n - (moolen[i-1]+i+3));
    else
        if(n - moolen[i-1] == 1) cout << 'm';
        else cout << 'o';
}

int main(){
    cin >> N;
    get_char(get_moolen(), N);
}