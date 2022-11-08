#include <stdio.h>

int main(void){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);

	if(a>1&&a<=10000&&b>1&&b<=10000&&c>1&&c<=10000){
		printf("%d\n%d\n%d\n%d",(a+b)%c,(a%c+b%c)%c,(a*b)%c,(a%c*b%c)%c);

	}


	return 0;
}
