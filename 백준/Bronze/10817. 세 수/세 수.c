#include <stdio.h>

void swap(int *p1,int *p2){
	int temp=*p1;
	*p1=*p2;
	*p2=temp;
}

int main(void){
	int n[3],i,j,max;
	scanf("%d %d %d",n,n+1,n+2);
	if(0<n[0]&&100>=n[0]&&0<n[1]&&100>=n[1]&&0<n[2]&&100>=n[2]){
		for(i=0;i<3;i++){
			max=i;
			for(j=i+1;j<3;j++){
				if(n[j]>n[max]) max=j;
			}
			swap(n+i,n+max);
		}
	}
	printf("%d",n[1]);


	return 0;
}
