#include <stdio.h>
int main(void){
	int n,i,sum=0;
	char *s = malloc(sizeof(char)*n+1);
	scanf("%d\n%s",&n,s);
	for(i=0;s[i];i++) sum+=s[i]-'0';		
	printf("%d",sum);
	return 0;
}
