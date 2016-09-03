#include <cstdio>
#include <cstring>

const int MAXN = 24;

int n, x;
long long dp[MAXN + 5][MAXN * 6 + 5];


long long solve(int dice, int sum){
	if(dice == 0)
		return (sum >= x) ? 1 : 0;
	long long &a = dp[dice][sum];
	if(a != -1)
		return a;
	a = 0;
	for(int i = 1; i <= 6; i++){
		a += solve(dice - 1, sum + i);
	}
	return a;
}

long long pot(int n){
	long long ans = 1;
	while(n--)
		ans *= 6;
	return ans;
}

long long gcd(long long a, long long b){
	return (b == 0) ? a : gcd(b, a % b);
}

int main(){
	while(scanf("%d %d", &n, &x), n){
		memset(dp, -1, sizeof dp);
		long long num = solve(n, 0);
		long long den = pot(n);
		long long mdc = gcd(den, num);
		num /= mdc;
		den /= mdc;
		if(den > 1)
			printf("%lld/%lld\n", num, den);
		else printf("%lld\n", num);
	}
	return 0;
}