#include <cstdio>
#include <cstring>

int fat[15];
int dp[15];

int solve(int n){
	if(n == 2)
		return 1;
	int &a = dp[n];
	if(a != -1)
		return a;
	if(n % 2) return a = n * solve(n - 1) - 1;
	return a = n * solve(n - 1) + 1;
}

int fatF(int n){
	if(n == 2) return 2;
	int &a = fat[n];
	if(a != -1)
		return a;
	return a = n * fatF(n - 1);
}

int main(){
	memset(dp, -1, sizeof dp);
	memset(fat, -1, sizeof fat);
	int tests;
	scanf("%d", &tests);
	while(tests--){
		int n;
		scanf("%d", &n);
		printf("%d/%d\n", solve(n), fatF(n));
	}

	return 0;
}