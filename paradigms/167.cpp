#include<bits/stdc++.h>
using namespace std;

bitset<30> row, firstD, seD;
int maxSum;
int Row[10];
int A[10][10];

void backtracking(int c){
	if(c == 8){
		int sum = 0;
		for(int i = 0; i < 8; i++) sum += A[Row[i]][i];
		if(sum > maxSum) maxSum = sum;
		return; }
	for(int r = 0; r < 8; r++){
		if(!row[r] && !firstD[r - c + 8 - 1] && !seD[r + c]){
			Row[c] = r;
			row[r] = firstD[r - c + 8 - 1] = seD[r + c] = 1;
			backtracking(c + 1);
			row[r] = firstD[r - c + 8 - 1] = seD[r + c] = 0;
		}
	}
}

int main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--){
		maxSum = 0;
		row.reset();
		firstD.reset();
		seD.reset();

		for(int i = 0; i < 8; i++){
			for(int j = 0; j < 8; j++) scanf(" %d", &A[i][j]); }

		backtracking(0);
		printf("%5d\n", maxSum);
	}

	return 0;
}