#include <stdio.h>

int main(void){
	int n,i,j,min,temp;
	scanf("%d",&n);
	int* arr = malloc(sizeof(int)*n);
	for(i=0;i<n;i++) scanf("%d",arr+i);
	for(i=0;i<n;i++){
		min=i;
		for(j=i+1;j<n;j++) if(arr[j]<arr[min]) min=j;
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
	for(i=0;i<n;i++) printf("%d\n",arr[i]);
	return 0;
}
