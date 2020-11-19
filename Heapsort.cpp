#include <stdio.h>

void heap(int *arr, int num){
	for(int i=1; i<num; i++){
		int child = i;
		while(child > 0){
			int root = (child-1)/2;
			if(arr[root] < arr[child]){
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
		child = root;
		}
	}
}

int main()
{
    
    //2019017410_문명균_12838
	
	int L1;
	int L2;
	int i;
	int arr[100001];

	scanf("%d", &L1);
	scanf("%d", &L2);
	
	for (i = 0; i < L1; i++){
		scanf("%d", &arr[i]);
	}

	heap(arr, L1);

	for(int i=L1-1; i>=L1-L2; i--){
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		heap(arr, i);
	}
		
	for (i = L1-1; i >= L1-L2; i--){
		printf("%d ", arr[i]);
	}
	printf("\n");

	for (i = 0; i < L1-L2; i++){
		printf("%d ", arr[i]);
	}
	
	return 0;
}