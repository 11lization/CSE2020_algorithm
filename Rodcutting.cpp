#include <stdio.h>

int main(){
	
	//2019017410_Moon MyeongKyun_12838
	
	int N, q, count, temp; 
	int p[101], r[101], s[101], t[100];
	
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &p[i]);
	}
	
	r[0] = 0;
	s[0] = 0;
	for(int j = 1; j <= N; j++){
		q = -1;
		for(int i = 1; i <= j; i++){
			if(q < p[i] + r[j-i]){
				q = p[i] + r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	
	printf("%d\n", r[N]);
	
	count = 0;
	for(int i = 0; N > 0; i++){
		t[i] = s[N];
		N = N - s[N];
		count++;
	}
	
	for(int i = 0; i < count; i++){
		for(int j = i + 1; j < count; j++){
			if(t[i] > t[j]){
				temp = t[i];
				t[i] = t[j];
				t[j] = temp;
			}
		}
	}
	
	for(int i = 0; i < count; i++){
		printf("%d ", t[i]);
	}
	
	return 0;
}
