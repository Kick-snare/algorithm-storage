#include <stdio.h>

int main(void){

	int n,i;
	scanf("%d",&n);
	if(n>1&&n<10){
		for(i=1;i<10;i++)
			printf("%d * %d = %d\n",n,i,n*i);
	}
	return 0;
}
