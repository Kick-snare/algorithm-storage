#include <iostream>
#include <string>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    for(;t--;){
        int r;
        string p;
        cin >> r >> p;
 
        for(auto j : p)
            for(int k=0;k<r;k++) cout << j;
        cout << '\n';
    }
}