#include <stdio.h>

int main(void){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a<=10000&&b<=10000&&a>0&&b>0){
		printf("%d\n%d\n%d\n%d\n%d",a+b,a-b,a*b,a/b,a%b);

	}



	return 0;
}
