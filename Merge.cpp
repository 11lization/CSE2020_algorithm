#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int p, int q, int r){
	int n1=q-p+1;
	int n2=r-q;
	int L[n1+1], R[n2+1];
	int i,j,k;
	
	for(i=0; i<n1; i++)
		L[i] = A[p+i];
	for(j=0; j<n2; j++)
		R[j] = A[q+j+1];
	L[n1] = 2147483647;
	R[n2] = 2147483647;
	
	i=0;
	j=0;
	
	for(k=p; k<r+1; k++){
		if (L[i]<=R[j]){
			A[k]=L[i];
			i = i+1;
		}
		else {
			A[k]=R[j];
			j = j+1;
		}
	}
}

void MergeSort(int A[],int p, int r){
	int q;
	
	if(p<r){
		q=(p+r)/2;
		
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}


int main(){
	int limit;
	int i;
	
	scanf("%d",&limit);
	
	int* arr;
	arr = (int*)malloc(sizeof(int)*limit);
	
	for(i=0; i<limit; i++){
		scanf("%d", &arr[i]);
	}
	
	MergeSort(arr,0,limit-1);
	
	for(i=limit-1; i>=0; i--)
		printf("%d\n", arr[i]);
	
	return 0;
}