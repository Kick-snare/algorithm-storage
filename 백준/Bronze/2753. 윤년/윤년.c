#include <stdio.h>

int main()
{
	int year;
	scanf("%d",&year);
	if(!(year%4)&&(!(year%400)||year%100)) printf("1");
	else printf("0");
	return 0;
}