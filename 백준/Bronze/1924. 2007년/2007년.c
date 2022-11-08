#include <stdio.h>

int main(void){
	int n1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char n2[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int x,y,sum=0;
	scanf("%d %d",&x,&y);
	if(0<x&&x<=12&&0<y&&y<=31){
		if(x==1) printf("%s",n2[(y-1)%7]);
		else{
			while(x-->1) sum+=n1[x-1];
			sum+=y-1;
			printf("%s",n2[sum%7]);
		}		
	}
	return 0;
}
