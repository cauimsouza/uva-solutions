#include <bits/stdc++.h>
using namespace std;

const int MAXCASH = 10210;
const int MAXN = 110;

int main(){
	int memo[MAXN][MAXCASH], price[MAXN], favour[MAXN];
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF){
		memset(memo, 0, sizeof memo);
		for(int i = 1; i <= n; i++) scanf("%d %d", &price[i], &favour[i]);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m + 200; j++)
				if(price[i] > j) memo[i][j] = memo[i-1][j];
				else memo[i][j] = max(memo[i-1][j], favour[i] + memo[i-1][j - price[i]]);
		
		int idx;
		bool entrou= false;
		for(idx = m + 200; idx > 2000; idx--){
			entrou = true;
			if(memo[n][idx] != memo[n][idx-1]) break;
		}
		if(idx == 2000 && entrou) idx  = m;
		else if(!entrou) idx = m;
		printf("%d\n", memo[n][idx]);
	}
}