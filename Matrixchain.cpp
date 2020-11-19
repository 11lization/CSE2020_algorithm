#include <stdio.h>
#include <math.h>

void printing(int s[][101], int i, int j){
	if(i==j){
		printf("%d ", i);
	}
	else{
		printf("( ");
		printing(s, i, s[i][j]);
		printing(s, s[i][j] + 1, j);
		printf(") ");
	}
}

int main(){
	
	//2019017410_Moon MyeongKyun_12838
	
	int N, j, q;
	int p[102];
	int m[101][101], s[101][101];
	
	scanf("%d", &N);

	for(int i = 1; i <= N+1; i++){
		scanf("%d", &p[i]);
	}

	for(int i = 1; i <= N; i++){
		m[i][i] = 0;
	}
	
	for(int l = 2; l <= N; l++){
		for(int i = 1; i <= N - l + 1; i++){
			j = i + l - 1;
			m[i][j] = INFINITY;
			for(int k = i; k <= j - 1; k++){
				q = m[i][k] + m[k + 1][j] + p[i]*p[k+1]*p[j+1];
				if(q < m[i][j]){
					m[i][j] = q;
					s[i][j] = k;
				}
			} 
		}
	}

	printf("%d\n", m[1][N]);
	printing(s, 1, N);
	
	return 0;

}
