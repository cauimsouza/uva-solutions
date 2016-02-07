#include<bits/stdc++.h>
using namespace std;

bitset<30> row, firstD, seD;
int dim, numSol;
char A[20][20];

void backtracking(int c){
	if(c == dim){
		numSol++; return; }
	for(int r = 0; r < dim; r++){
		if(A[r][c] != '*' && !row[r] && !firstD[r - c + dim - 1] && !seD[r + c]){
			row[r] = firstD[r - c + dim - 1] = seD[r + c] = 1;
			backtracking(c + 1);
			row[r] = firstD[r - c + dim - 1] = seD[r + c] = 0;
		}
	}
}

int main()
{
	int caseNum = 1;
	while(scanf("%d", &dim), dim){
		numSol = 0;
		row.reset();
		firstD.reset();
		seD.reset();

		for(int i = 0; i < dim; i++){
			for(int j = 0; j < dim; j++) scanf(" %c", &A[i][j]); }

		backtracking(0);
		printf("Case %d: %d\n", caseNum++, numSol);
	}

	return 0;
}