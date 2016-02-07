#include <bits/stdc++.h>
using namespace std;

int k, order;
bool sol;
char fir[10][10], sec[10][10], letters[10];

void backtracking(int idx){
	if(sol) return; // we already print the solution
	if(idx == 5){ // a new possible password was found
		order++;
		if(order == k){
			sol = true;
			for(int i = 0; i < 5; i++) putchar(letters[i]);
			printf("\n");
		}
		return;
	}

	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 6; j++){
			if(fir[idx][i] == sec[idx][j]){
				letters[idx] = fir[idx][i];
				backtracking(idx + 1);
				break;
			}
		}
		while(i < 5 && fir[idx][i] == fir[idx][i+1]) i++;
	}
}

int main(){
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		scanf("%d", &k);
		// reading input
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++)
				scanf(" %c", &fir[j][i]); }
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 5; j++)
				scanf(" %c", &sec[j][i]); }
		// sorting columns
		for(int i = 0; i < 5; i++){
			sort(fir[i], fir[i] + 6);
			sort(sec[i], sec[i] + 6); }
		
		order = sol = 0;
		backtracking(0);
		if(!sol) printf("NO\n");
	}

	return 0;
}
