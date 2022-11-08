#include <stdio.h>

int main(void){

	int n,x,i;
	scanf("%d %d",&n,&x);
	int *p = malloc(sizeof(int)*n);
	if(n>0&&n<=10000&&x>0&&x<=10000){
		for(i=0;i<n;i++){
			scanf("%d",p+i);
			if(p[i]<x) printf("%d ",p[i]);
		}
	}
	return 0;
}
