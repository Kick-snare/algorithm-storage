#include <stdio.h>

int main(void){

	int n,i,on=0;
	scanf("%d",&n);
	
	if(n>=3&&n<=5000){
		for(i=n/5;i>=0;i--){
			if((n-5*i)%3==0) {
				printf("%d",(n-5*i)/3+i+on++);
				break;
			}
		}
		if(!on) printf("%d",-1);
	}

	return 0;
}
