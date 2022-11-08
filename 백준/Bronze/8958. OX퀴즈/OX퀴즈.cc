#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string quiz;
        cin >> quiz;
        quiz+='X';
        int sum=0, cnt=0;
        for(int i=0;i<quiz.length();i++){
            if(quiz[i]=='O') cnt++;
            else cnt=0;
            sum+=cnt;
        }
        cout << sum << '\n';
    }   
}