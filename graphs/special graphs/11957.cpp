#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000007;

int n;
char grid[105][105];
int memo[105][105];

int solve(int r, int c){
	if(r == 0)
		return 1;
	int &a = memo[r][c];
	if(a != -1)
		return a;
	a = 0;
	if(c){
		// se diagonal a esquerda esta vazia
		if(grid[r - 1][c - 1] == '.')
			a += solve(r - 1,c - 1);
		// se existe uma peca negra na diagonal a esquerda e posso pula-la
		else if(c > 1 && r > 1 && grid[r - 2][c - 2] == '.')
			a += solve(r - 2, c - 2);
	}
	if(c < n - 1){
		// se diagonal a direita esta vazia
		if(grid[r - 1][c + 1] == '.')
			a += solve(r - 1, c + 1);
		// se existe uma peca negra na diagonal a direita e posso pula-la
		else if(c < n - 2 && r > 1 && grid[r - 2][c + 2] == '.')
			a += solve(r - 2, c + 2);
	}
	a %= MOD;
	return a;
}

int main(){
	int casos;
	cin >> casos;
	for(int caso = 1; caso <= casos; caso++){
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf(" %c", &grid[i][j]);

		memset(memo, -1, sizeof memo);

		int r, c;
		bool found = false;
		for(int i = 0; !found && i < n; i++)
			for(int j = 0; j < n; j++)
				if(grid[i][j] == 'W'){
					r = i;
					c = j;
					found = true;
				}

		printf("Case %d: %d\n", caso, solve(r, c));
	}
}