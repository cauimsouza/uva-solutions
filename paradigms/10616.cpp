#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210;
const int MAXM = 25;
int n, d, m;
int num[MAXN];
int memo[MAXN][MAXN][MAXN];	

int solve(int id, int mod, int qnt){
	if(qnt == m) return mod ? 0 : 1; // we have already choosed m numbers
	if(id == n) return 0; // cannot try further
	int &a = memo[id][qnt][mod];
	if(a != -1) return a;
	return a = solve(id + 1, mod, qnt) + solve(id + 1, (mod + num[id])%d, qnt + 1);
}

int main(){
	int cont = 1;
	int q;
	while(scanf("%d %d", &n, &q), n){
		for(int i = 0; i < n; i++) scanf("%d", &num[i]);

		printf("SET %d:\n", cont++);
		int query = 1;
		while(q--){
			scanf("%d %d", &d, &m);
			memset(memo, -1, sizeof memo);
			printf("QUERY %d: %d\n", query++, solve(0, 0, 0));
		}
	}
}