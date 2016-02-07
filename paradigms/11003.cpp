#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;
const int MAXW = 3010;
const int inf = 1e9;

int memo[MAXN][MAXW], weight[MAXN], load[MAXN];
int n;
int rec(int box, int remW){
	if(box == n || remW == 0) return 0;
	if(remW == inf) return max(rec(box + 1, inf), 1 + rec(box + 1, load[box]));
	if(memo[box][remW] != -1) return memo[box][remW];
	if(remW < weight[box]) return memo[box][remW] = rec(box + 1, remW);
	return memo[box][remW] = max(rec(box + 1, remW), 1 + rec(box + 1, min(remW - weight[box], load[box])));
}

void solve(){
	memset(memo, -1, sizeof memo);
	for(int i = 0; i < n; i++) scanf("%d %d", &weight[i], &load[i]);

	printf("%d\n", rec(0, inf));
}

int main(){
	while(scanf("%d", &n), n)
		solve();
}