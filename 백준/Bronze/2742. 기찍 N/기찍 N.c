#include <stdio.h>

int main(void){

	int n;
	scanf("%d",&n);
	if(n<=100000){
		while(n>0){
			printf("%d\n",n--);
		}
	}


	return 0;
}
