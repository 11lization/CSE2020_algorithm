#include <stdio.h>

int main(){
	int arr[30000], limit;
	int i,j,temp;
	
	scanf("%d",&limit);
	
	for(i=0; i<limit; i++){
		scanf("%d", &arr[i]);
	}
	
	for(i=1; i<limit; i++){
		j=i;
		while(j>0 && arr[j]>arr[j-1]){
			temp=arr[j];
			arr[j]=arr[j-1];
			arr[j-1]=temp;
			
			j--;
		}
	}
	
	for(i=0; i<limit; i++)
		printf("%d\n", arr[i]);
	
	return 0;
}
	
	