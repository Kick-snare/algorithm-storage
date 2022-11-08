#include <stdio.h>

int main(void){

	int n,i;
	scanf("%d",&n);
	if(n<=100000&&n>0){
		for(i=0;i<n;i++) printf("%d\n",i+1);

	}
	return 0;
}
