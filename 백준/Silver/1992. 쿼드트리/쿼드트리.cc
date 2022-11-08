#include <iostream>
#include <string>
using namespace std;

bool video[64][64];

void find_quadtree(int x, int y, int size){
    if(!size) return;

    int sum = 0;
    for(int i=y;i<y+size;i++)
        for(int j=x;j<x+size;j++)
            sum += video[i][j];

    if(!sum || sum==size*size){
        if(sum) cout << 1;
        else cout << 0;
        return;
    }
    else{
        cout << '(';
        for(int i=y;i<y+size;i+=size/2)
            for(int j=x;j<x+size;j+=size/2)
                find_quadtree(j,i,size/2);
        cout << ')';
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N;
    string tmp;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> tmp;
        for(int j=0;j<N;j++) video[i][j] = tmp[j] - '0';
    }
    find_quadtree(0,0,N);
}