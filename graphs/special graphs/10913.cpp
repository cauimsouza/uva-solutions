#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int CIMA = 0, ESQ = 1, DIR = 2;

int n;
int grid[80][80];
int memo[80][80][6][3];

int solve(int r, int c, int neg_left, int last){
	// if we are out of the grid
	if(r >= n || c < 0 || c >= n)
		return -INF;
	// if we are on a negative square, decrement neg_left
	if(grid[r][c] < 0)
		neg_left--;
	// we've stepped over more negative squares than the limit
	if(neg_left < 0)
		return -INF;
	// we've just reached the destination
	if(r == n - 1 && c == n-1)
		return grid[r][c];

	int &a = memo[r][c][neg_left][last];
	if(a != -1)
		return a;
	if(last == CIMA){
		a = solve(r, c - 1, neg_left, DIR);
		a = max(a, solve(r, c + 1, neg_left, ESQ));
		a = max(a, solve(r + 1, c, neg_left, CIMA));
	}
	else if(last == DIR){
		a = solve(r, c - 1, neg_left, DIR);
		a = max(a, solve(r + 1, c, neg_left, CIMA));
	}
	else{
		a = solve(r, c + 1, neg_left, ESQ);
		a = max(a, solve(r + 1, c, neg_left, CIMA));
	}
	return a = a + grid[r][c];
}

int main(){
	int k, caso = 1;
	while(scanf("%d %d", &n, &k), n){
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &grid[i][j]);

		memset(memo, -1, sizeof memo);
		int ans = solve(0, 0, k, CIMA);
		printf("Case %d: ", caso++);
		if(ans >= - 1e5)
			printf("%d\n", ans);
		else
			printf("impossible\n");
	}
}