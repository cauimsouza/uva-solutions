#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAXN = 605;
const int MAXK = 305;

int n;
int dist[MAXN];
int dp[MAXN];
int memo[MAXN][MAXK];

int solve(int camp, int remK){
	if(remK == 0){
		return dp[n + 1] - dp[camp];
	}
	int &a = memo[camp][remK];
	if(a != -1)
		return a;
	
	a = dp[n + 1] - dp[camp];
	for(int i = camp + 1; i <= n; i++){
		a = min(a, max(dp[i] - dp[camp], solve(i, remK - 1)));
	}
	
	return a;	
}

int main(){
	int k;
	while(scanf("%d %d", &n, &k) == 2){
		dp[0] = 0;
		for(int i = 0; i <= n; i++){
			scanf("%d", &dist[i]);
			dp[i + 1] = dp[i] + dist[i];
		}

		memset(memo, -1, sizeof memo);
		printf("%d\n", solve(0, min(k, n)));
	}
}