//2019017410_Moon MyeongKyun_12838

#include <stdio.h>
#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>

using namespace std;

int N, M;

class E{
public:
	int dest;
	int PATH;

	E(int dest, int PATH){
		this -> dest = dest;
		this -> PATH = PATH;
	}
};

class V{
public:
	int tot;
	bool picked;
	vector<E> edge;

	V(){
		this -> tot = INT_MAX;
		this -> picked = false;
	}
};

int calc(vector<V> &vn){
	
	int mini = INT_MAX;
	int k = -1;
	for(int i = 1; i <= N; i++){
		if(vn[i].picked == false && mini > vn[i].tot){
			mini = vn[i].tot;
			k = i;
		}
	}

	return k;
}

int main(void){
	
	int a,b,c;
	int count = 0;
	int mtot = -1;
	
	scanf("%d %d",&N,&M);

	vector<V> vn(N+1);

	for(int i = 0; i < M; i++){
		scanf("%d %d %d",&a,&b,&c);
		vn[a].edge.push_back(E(b,c));
	}

	vn[1].tot = 0;

	while(count < N){
		int min = calc(vn);
		V &now = vn[min];
		int pathnum = now.edge.size();
		for(int i = 0; i < pathnum; i++){
			int destination = now.edge[i].dest;
			int PATH = now.edge[i].PATH;
			
			if(vn[destination].tot > now.tot + PATH){
				vn[destination].tot = now.tot + PATH;
			}
		}
		now.picked = true;
		count++;
	}

	for(int i = 1; i <= N; i++){
		if(mtot < vn[i].tot){
			mtot = vn[i].tot;
		}
	}

	printf("%d\n", mtot);

	return 0;
	
}
