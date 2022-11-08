#include <stdio.h>
int sum_cycle(int n,int* pn,int c){
	c++;
	int a=n/10,b=n%10;
	if(b*10+(a+b)%10==*pn) return c;
	sum_cycle(b*10+(a+b)%10,pn,c);
}
int main(void){
	int n;
	scanf("%d",&n);
	printf("%d",sum_cycle(n,&n,0));
	return 0;
}
