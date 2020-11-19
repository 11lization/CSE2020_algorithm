#include <stdio.h>

int main(){
	
	//2019017410_문명균_12838
	
	int L1, L2;
	int A[100000], B[100000];
	int i,j,count=0;
	
	scanf("%d", &L1);
	scanf("%d", &L2);
	
	for(i=0; i<L1; i++){
	    scanf("%d", &A[i]);
	}    
	
	for(j=0; j<L2; j++){
	    scanf("%d", &B[j]);
    }
    
    for(i=0; i<L1; i++){
        for(j=0; j<L2; j++){
            if(A[i]==B[j])
                count++;
        }
    }

    printf("%d", count);

	return 0;
}
	