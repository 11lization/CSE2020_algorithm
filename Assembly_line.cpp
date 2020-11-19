#include <stdio.h>

int main(){
	
	//2019017410_Moon MyeongKyun_12838
	
	int N, e1, e2, x1, x2, lf, sf, trace; 
	int a1[101], a2[101], t1[101], t2[101], s1[101], s2[101], l1[101], l2[101], result[101];
	
	scanf("%d", &N);
	scanf("%d", &e1);
	scanf("%d", &e2);
	scanf("%d", &x1);
	scanf("%d", &x2);
	for(int i = 1; i <= N; i++){
		scanf("%d", &a1[i]);
	}
	for(int i = 1; i <= N; i++){
		scanf("%d", &a2[i]);
	}
	for(int i = 1; i <= N-1; i++){
		scanf("%d", &t1[i]);
	}
	for(int i = 1; i <= N-1; i++){
		scanf("%d", &t2[i]);
	}
	
	s1[1] = e1 + a1[1];
	s2[1] = e2 + a2[1];
	
	for(int j = 2; j <= N; j++){
		if(s1[j-1] <= s2[j-1] + t2[j-1]){
			s1[j] = s1[j-1] + a1[j];
			l1[j] = 1;
		}
		else{
			s1[j] = s2[j-1] + t2[j-1] + a1[j];
			l1[j] = 2;
		}
		if(s2[j-1] <= s1[j-1] + t1[j-1]){
			s2[j] = s2[j-1] + a2[j];
			l2[j] = 2;
		}
		else{
			s2[j] = s1[j-1] + t1[j-1] + a2[j];
			l2[j] = 1;
		}
	}
	if(s1[N] + x1 <= s2[N] + x2){
		sf = s1[N] + x1;
		lf = 1;
	}
	else{
		sf = s2[N] + x2;
		lf = 2;
	}
	
	printf("%d\n", sf);
	
	trace = lf;
	for(int i = N; i >= 1; i--){
		result[i] = trace;
		if(result[i] == 1){
			trace = l1[i];
		}
		else{
			trace = l2[i];
		}
	}
	
	for(int i = 1; i <= N; i++){
		printf("%d %d\n", result[i], i);
	}
	
	return 0;
}
