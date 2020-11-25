#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
	char str[5];
	int number;
	struct heap* leftChild;
	struct heap* rightChild;
}HEAP;

HEAP* MIN[60001];

int SIZE = 0;
int N = 0;
int RESULT = 0;
int TOTAL = 0;

void pDown(int);
void minHEAP();
void pUp(int);
HEAP* buildHuffman();
HEAP* extractMin();
void calcHuffman(HEAP*,int);
int calcBitnum();

int main(void){

// 2019017410_MoonMyeongKyun_12838
	
	scanf("%d",&N);
	int i = 0;

	for(i = 0; i < N; i++){
		MIN[i] = (HEAP*)malloc(sizeof(HEAP));
		scanf("%s",MIN[i]->str);
		scanf("%d",&(MIN[i]->number));
	}

	scanf("%d",&TOTAL);
	SIZE = N;

	if(SIZE <= 1){
		printf("%d\n",TOTAL);
		printf("%d\n",TOTAL);
	}else{

		minHEAP();
		HEAP* startNode = buildHuffman();
		calcHuffman(startNode,0);

		printf("%d\n%d\n",calcBitnum()*TOTAL,RESULT);
	}
	return 0;
}

void minHEAP(){
	int mid = (int)(SIZE/2)-1;
	int i = 0;

	for(i = mid; i >= 0; i--){
		pDown(i);
	}

}

void pDown(int curPos){
	HEAP* left = NULL;
	HEAP* right = NULL;

	if((2*(curPos+1) - 1) < SIZE && (2*(curPos+1) < SIZE)){;
		left = MIN[2*(curPos+1)-1];
		right = MIN[2*(curPos+1)];

		if(MIN[curPos]->number > left->number || MIN[curPos]->number > right->number){
			if(left->number < right->number){
				HEAP* temp = MIN[curPos];
				MIN[curPos] = MIN[2*(curPos+1)-1];
				MIN[2*(curPos+1)-1] = temp;
				pDown(2*(curPos+1)-1);
			}else{
				HEAP* temp = MIN[curPos];
				MIN[curPos] = MIN[2*(curPos+1)];
				MIN[2*(curPos+1)] = temp;
				pDown(2*(curPos+1));
			}
		}
	}else if(2*(curPos+1) - 1 < SIZE){
		if(2*(curPos+1)-1 < SIZE)
			left = MIN[2*(curPos+1)-1];

		if(MIN[curPos]->number > left->number){
			HEAP* temp = MIN[curPos];
			MIN[curPos] = MIN[2*(curPos+1)-1];
			MIN[2*(curPos+1)-1] = temp;
		}
	}else{
		return;
	}
}

void pUp(int curPos){
	if(curPos > 0){
		int parentPos = 0;
		if(curPos%2 == 0)
			parentPos = (int)((curPos/2)-1);
		else
			parentPos = (int)((curPos/2));
		
		if(MIN[parentPos]->number > MIN[curPos]->number){
			HEAP* temp = MIN[parentPos];
			MIN[parentPos] = MIN[curPos];
			MIN[curPos] = temp;

			pUp(parentPos);
		}
	}
}

HEAP* buildHuffman(){
	while(SIZE > 1){
		HEAP* leftNode = NULL;
		HEAP* rightNode = NULL;
		HEAP* parentNode = (HEAP*)malloc(sizeof(HEAP));

		leftNode = extractMin();
		rightNode = extractMin();

		parentNode -> str[0] = '\0';
		parentNode -> number = leftNode -> number + rightNode -> number;
		parentNode -> leftChild = leftNode;
		parentNode -> rightChild = rightNode;

		MIN[SIZE++] = parentNode;
		pUp(SIZE-1);
	}
	return extractMin();
}

HEAP* extractMin(){
	HEAP* extracted = MIN[0];
	MIN[0] = MIN[--SIZE];

	pDown(0);
	return extracted;
}

void calcHuffman(HEAP* curNode,int bitNum){
	if(curNode->str[0] == '\0'){
		calcHuffman(curNode->leftChild,bitNum+1);
		calcHuffman(curNode->rightChild,bitNum+1);
	}else if((curNode->leftChild == NULL) && (curNode->rightChild == NULL)){
		RESULT += ((curNode->number)*bitNum);
	}
}

int calcBitnum(){
	int i = 0;
	int power = 1;
	for(i = 1; power*2 < N; i++){
		power *= 2;
	}

	return i;
}

