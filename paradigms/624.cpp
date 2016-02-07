#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
int trackTime[30];
int maxDuration, N, tracks, bm, bmMaxDuration;

void backtracking(int soma, int i, int bm){
	soma += trackTime[i];
	if(soma > N) return;
	bm |= (1 << i);
	if(soma > maxDuration){
		maxDuration = soma;
		bmMaxDuration = bm;
	}
	for(int j = i + 1; j < tracks; j++)
		backtracking(soma, j, bm);
}

void backtracking(){
	for(int i = 0; i < tracks; i++)
		backtracking(0, i, 0);
}

int main(){

	while(scanf("%d", &N) != EOF){
		scanf("%d", &tracks);
		maxDuration = bm = bmMaxDuration = 0;
		for(int i = 0; i < tracks; i++)
			scanf("%d", &trackTime[i]);


		backtracking();

		for(int i = 0; i < tracks; i++)
			if(bmMaxDuration & (1 << i)) printf("%d ", trackTime[i]);
		printf("sum:%d\n", maxDuration);
	}

	return 0;
}