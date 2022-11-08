#include <stdio.h>

int main(void){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a>0&&a<10&&b<10&&b>0){
	
	printf("%.9lf",(double)a/b);
	}
	return 0;
}
