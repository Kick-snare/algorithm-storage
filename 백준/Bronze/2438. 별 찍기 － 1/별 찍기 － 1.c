#include <stdio.h>

int main(void){

	int n,i,j;
	scanf("%d",&n);
	if(1<=n&&n<=100){
		for(i=1;i<n+1;i++){
			for(j=0;j<i;j++) printf("*");
		printf("\n");
		}
		
	}


	return 0;
}
