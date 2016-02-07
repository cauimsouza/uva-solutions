#include <bits/stdc++.h>
using namespace std;

const int MAX_T = 1010;
const int MAX_N = 40;

int main(){
	int memo[MAX_N][MAX_T];
	int value[MAX_N], depth[MAX_N];
	int t, w, n;
	int caso = 0;

	while(scanf("%d %d %d", &t, &w, &n) != EOF){
		if(caso++) printf("\n");
		for(int i = 1; i <= n; i++) scanf("%d %d", &depth[i], &value[i]);
		
		for(int i = 0; i <= t; i++) memo[0][i] = 0;
		for(int i = 0; i <= n; i++) memo[i][0] = 0;

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= t; j++){
				if(3*w*depth[i] > j) memo[i][j] = memo[i-1][j];
				else memo[i][j] = max(memo[i-1][j], value[i] + memo[i-1][j - 3*w*depth[i]]);
			}

		int mask = 0, cont = 0;
		int i = n, j = t;
		while(i){
			if(memo[i][j] != memo[i-1][j]){
				mask |= 1 << i;
				j -= 3 * w * depth[i];
				cont++;
			}
			i--;
		}
		printf("%d\n%d\n", memo[n][t], cont);
		for(int k = 1; k <= n; k++)
			if(mask & (1 << k)) printf("%d %d\n", depth[k], value[k]);
	}
}