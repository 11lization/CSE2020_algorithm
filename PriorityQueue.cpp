#include <stdio.h>

void swap(int &num1, int &num2){
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(){
	
	//2019017410_문명균_12838
	
	int A[100001], B[100000];
	int Anum = 0, Bnum = 0, on=1, i, menu;
	int child, parent, temp;
	
	while(on){
		
		scanf("%d", &menu);
		switch(menu){
			case(0):
				for (i=0; i<Bnum; i++){
					printf("%d ", B[i]);
				}
				printf("\n");
				for (i=1; i<=Anum; i++){
					printf("%d ", A[i]);
				}
				on=0;
				break;
			case(1):
				scanf("%d", &A[Anum+1]);
				Anum++;
				child = Anum;
				parent = child/2;
				while((parent!=0)&&(A[parent]<A[child])){
					swap(A[parent], A[child]);
					child = parent;
					parent = child/2;
				}
				break;
			case(2):
				if(Anum>0){
					B[Bnum] = A[1];
					Bnum++;
					A[1] = A[Anum];
					Anum--;
					parent = 1;
					child = 2;
					if((Anum>2)&&(A[3]>A[2])){
						child = 3;
					}
					if((Anum>child)&&(A[child+1]>=A[child])){
						child++;
					}
					while ((child<=Anum)&&(A[parent]<A[child])){
						swap(A[parent], A[child]);
						parent = child;
						child = parent*2;
						if ((Anum>child)&&(A[child+1]>=A[child])){
							child++;
						}
					}
				}
				break;
			case(3):
				scanf("%d", &child);
				scanf("%d", &temp);
				if (child<=Anum){
					A[child] = temp;
					parent = child / 2;
					if((parent>0)&&(A[parent]<A[child])){
						while(((parent>0)&&(A[parent]<A[child]))){
							swap(A[parent], A[child]);
							child = parent;
							parent = child/2;
						}
					}
					else
					{
						parent = child;
						child = parent*2;
						if((Anum>child)&&(A[child+1]>=A[child])){
							child++;
						}
						while((child<=Anum)&&(A[parent]<A[child])){
							swap(A[parent], A[child]);
							parent = child;
							child = parent*2;
							if ((Anum>child)&&(A[child+1]>=A[child]))
							{
								child++;
							}
						}
					}
				}
				else{
					A[Anum+1] = temp;
					Anum++;
					child = Anum;
					parent = child/2;
					while((parent!=0)&&(A[parent]<A[child])){
					swap(A[parent], A[child]);
					child = parent;
					parent = child/2;
					}
				}
				break;
			default:
				break;
		}
	}
	return 0;
}