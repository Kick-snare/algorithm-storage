#include <iostream>
#include <vector>
using namespace std;

int main(){
    int A,B;
    int N;
    vector<int> v;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A >> B;
        v.push_back(A+B);
    }
    for(auto a:v)
        cout << a << endl;
    return 0;
}