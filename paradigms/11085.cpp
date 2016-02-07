#include<bits/stdc++.h>
using namespace std;

int row, firstD, seD;
int minSum, sum;
int originalPos[10];
int A[10][10];

#define SETBit(S, i) ( (S) |= (1 << (i) ))
#define RESETBit(S, i) ( (S) &= ~(1 << (i)) )
#define TestBit(S, i) ( (S) & (1 << (i) ) )
 
void backtracking(int c){
	if(sum >= minSum) return;
	if(c == 8){
		minSum = sum;
		return; }
	for(int r = 0; r < 8; r++){
		if(!TestBit(row, r) && !TestBit(firstD, r-c+8-1) && !TestBit(seD,r+c) ){
			if(originalPos[c] - 1 != r) sum++; // another move
			SETBit(row,r); SETBit(firstD,r-c+8-1); SETBit(seD,r+c); 
			backtracking(c + 1);
			RESETBit(row,r); RESETBit(firstD,r-c+8-1); RESETBit(seD,r+c);
			if(originalPos[c] - 1!= r) sum--;
		}
	}
}

int main()
{
	int count = 1;
	while(scanf("%d", &originalPos[0]) != EOF){
		minSum = 8; sum = 0;
		row = firstD = seD = 0;

		for(int i = 1; i < 8; i++)
			scanf("%d", &originalPos[i]);

		backtracking(0);
		printf("Case %d: %d\n", count++, minSum);
	}

	return 0;
}