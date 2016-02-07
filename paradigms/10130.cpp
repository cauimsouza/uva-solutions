#include <bits/stdc++.h>
using namespace std;

const int MAX_W = 40;
const int MAX_N = 1010;

int main(){
	int memo[MAX_N][MAX_W];
	int value[MAX_N], weight[MAX_N];
	int tc;
	scanf("%d", &tc);

	while(tc--){
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n ; i++) scanf("%d %d", &value[i], &weight[i]);

		for(int i = 0; i <= 30; i++) memo[0][i] = 0;
		for(int i = 0; i <= n; i++) memo[i][0] = 0;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= 30; j++)
				if(weight[i] > j) memo[i][j] = memo[i-1][j];
				else memo[i][j] = max(memo[i-1][j], value[i] + memo[i-1][j - weight[i]]);

		int g, sum = 0;
		scanf("%d", &g);
		while(g--){
			int cap;
			scanf("%d", &cap);
			sum += memo[n][cap];
		}

		printf("%d\n", sum);
	}
}