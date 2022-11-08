#include <stdio.h>

int main(void){
	int i;
	char n[101];
	scanf("%s",n);
	
	for(i=1;n[i-1];i++){
		printf("%c",n[i-1]);
		if(i%10==0) printf("\n");
	}

	return 0;
}
