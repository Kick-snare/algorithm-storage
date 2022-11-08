#include <stdio.h>

int main(void){
	int count=0,count2=0,p=0;
	char n[1000001]={0,};
	gets(n);
	while(n[count2]==32) count2++;
	while(n[count2]!=0) {
		while(n[count2]!=0){
			if(!n[count2]) p=1;
			if(n[count2++]==32) break;
		}
		count++;
		if(p) break;
	}
	printf("%d",count);
	return 0;
}
