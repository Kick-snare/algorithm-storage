#include <stdio.h>

int main(){
    int i=0,n[100][101];
    while(i<100){
        fgets(n[i],sizeof(int)*101,stdin);
        n[i][100]='\0';
        printf("%s",n[i++]);
    }
    return 0;
}