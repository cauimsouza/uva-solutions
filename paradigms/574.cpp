#include <bits/stdc++.h>
using namespace std;

int t, n, bitmask;
int num[15];
bool sol;

void backtracking(int idx, int sum){
	if(sum > t) return;
	if(idx >= n){
		if(sum == t){
			sol = true;
			bool first = true;
			for(int i = 0; i < n; i++){
				if(bitmask & (1 << i)){
					if(!first) printf("+");
					printf("%d", num[i]);
					first = false;
				}
			}
			printf("\n");
		}
		return;
	}
	
	bitmask |= 1 << idx;
	backtracking(idx + 1, sum + num[idx]);
	bitmask ^= 1 << idx;
	while(++idx < n && num[idx] == num[idx - 1]);
	backtracking(idx, sum);	
}

int main(){

	while(scanf("%d%d", &t, &n), n){
		for(int i = 0; i < n; i++) scanf("%d", &num[i]);
		printf("Sums of %d:\n", t);
		sol = false;
		bitmask = 0;
		backtracking(0, 0);
		if(!sol) printf("NONE\n");
	}

	return 0;
}
