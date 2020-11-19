#include <stdio.h>

int main(){
    
    //2019017410_문명균_12838
    
	int L1, L2, L3;
	int N[100000], A[100000], B[100000];
	int i,j,count;
	
	scanf("%d", &L1);
	scanf("%d", &L2);
	scanf("%d", &L3);
	
	for(i=0; i<L3; i++){
	    scanf("%d", &A[i]);
	    scanf("%d", &B[i]);
	}
	
	for(j=0; j<L1; j++){
	    scanf("%d", &N[j]);
	}    
    
    for(i=0; i<L3; i++){
        count = 0;
        for(j=0; j<L1; j++){
            if(A[i] <= N[j] && B[i] >= N[j])
                count++;
        }
        printf("%d\n", count);
    }

	return 0;
}
	