#include <stdio.h>

int main(void){
	int n,i,j,k;
	scanf("%d",&n);
	
	if(n>0&&n<=100){
		for(i=0;i<=n;i++){
			for(j=i;j<n;j++){
				printf("*");
			}
		printf("\n");
		}
	}


	return 0;
}
