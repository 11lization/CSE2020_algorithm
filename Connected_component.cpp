//2019017410_Moon MyeongKyun_12838

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int source;
	struct node *v;
}node;

int *check = NULL;
node *Leaf = NULL;

void BFS(int adj,node *now){
	
	if(check[adj] != 1)
		check[adj] = 1;
	
	while(now->v != NULL){
		now = now->v;
		if(check[now->source] != 1)
			BFS(now->source,&Leaf[now->source]);
	}
	
	return;
}

int Trees = 0;

int main(){
	
	int N, M, u, v;
	
	scanf("%d %d", &N, &M);

	Leaf = (node*)malloc(sizeof(node)*(N + 1));
	check = (int*)malloc(sizeof(int)*(N + 1));

	for(int i = 0; i < N + 1 ; i++){
		check[i] = 0;
		Leaf[i].source = i;
		Leaf[i].v = NULL;
	}

	for(int i = 0; i < M; i++){
		
		scanf("%d %d", &u, &v);
		
		node *node1 = new node;
		node *node2 = new node;
		
		node1->source = v;
		node2->source = u;
		node1->v = NULL;
		node2->v = NULL;

		node *current = &Leaf[u];
		node *after = Leaf[u].v;


		while(after != NULL){
			current = current->v;
			after = current->v;
		}
		
		current->v = node1;

		after = Leaf[v].v;
		current = &Leaf[v];
		
		while(after != NULL){
			current = current->v;
			after = current->v;
		}
		
		current->v = node2;
	}

	for(int i = 1; i < N + 1; i++){
		if(check[i] == 0){
			BFS(i,&Leaf[i]);
			Trees++;
		}
	}
	
	printf("%d", Trees);

	return 0;
}