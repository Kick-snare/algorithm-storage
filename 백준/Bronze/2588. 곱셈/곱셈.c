#include <stdio.h>

int main(void)
{
	int n1,n2,a,b,c;
	scanf("%d\n%d",&n1,&n2);
	a=n2/100;
	b=(n2/10)%10;
	c=n2%10;
	int n3=n1*c;
	int n4=n1*b;
	int n5=n1*a;
	int n6=n3+10*n4+100*n5;
	printf("%d\n%d\n%d\n%d\n",n3,n4,n5,n6);
	return 0;
	
}