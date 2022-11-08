#include <stdio.h>
int sum(int num){
	if(!num) return 0; 
	return num + sum(num-1);
}

int main(void){

	int n;
	scanf("%d",&n);
	printf("%d",sum(n));
	return 0;
}
