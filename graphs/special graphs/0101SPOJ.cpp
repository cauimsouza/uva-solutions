/* SPOJ - 0101 - FISHER - Fishmonger */

#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
const int INF = 1e9;

int n;
ii memo[55][1010];
int toll[55][55];
int time_e[55][55];

ii go(int cur, int t_left){
	if(t_left < 0)
		return ii(INF,INF);
	if(cur == n-1)
		return ii(0, 0);
	ii &a = memo[cur][t_left];
	if(a != ii(-1,-1))
		return a;
	a = ii(INF,INF);
	for(int i = 0; i < n; i++){
		if(i == cur)
			continue;
		ii next = go(i, t_left - time_e[cur][i]);
		if(next.first + toll[cur][i] < a.first){
			a.first = next.first + toll[cur][i];
			a.second = next.second + time_e[cur][i];
		}
	}
	return a;
}

void solve(int t){
	// starting memo table
	for(int i = 0; i < 55; i++)
		for(int j = 0; j < 1010; j++)
			memo[i][j] = ii(-1,-1);
	// reading input
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &time_e[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &toll[i][j]);
	// top-down DP
	ii sol = go(0, t);
	printf("%d %d\n", sol.first, sol.second);
}

int main(){
	int t;
	while(scanf("%d %d", &n, &t), n)
		solve(t);
}