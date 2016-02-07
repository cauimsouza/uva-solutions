#include <bits/stdc++.h>
using namespace std;

int n, m, bitmask, choosen[20];
int f[20], s[20]; // first and second numbers of the pieces
bool sol;

void backtracking(int idx){
	if(idx > n){
		if(choosen[n] == f[m+1])
			sol = true;
		return; }
	
	for(int i = 1; !sol && i <= m; i++){
		if(!(bitmask & (1 << i)) && choosen[idx - 1] == f[i]){
			choosen[idx] = s[i];
			bitmask |= 1 << i;
			backtracking(idx + 1);
			bitmask ^= 1 << i;
		}
		if(!(bitmask & (1 << i)) && choosen[idx - 1] == s[i]){
			choosen[idx] = f[i];
			bitmask |= 1 << i;
			backtracking(idx + 1);
			bitmask ^= 1 << i;
		}
	}
}

int main(){

	while(scanf("%d", &n), n){
		scanf("%d", &m);
		scanf("%d%d", &f[0], &s[0]); // reading the left-most piece
		scanf("%d%d", &f[m+1], &s[m+1]); // reading the right-most piece

		for(int i = 1; i <= m; i++){ // reading the m pieces
			scanf("%d%d", &f[i], &s[i]); }
		choosen[0] = s[0];
		bitmask = sol = 0;
		backtracking(1);
		if(sol) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
