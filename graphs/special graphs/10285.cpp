#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;

int grid[MAXN][MAXN];
int memo[MAXN][MAXN];
int ans;
int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};
int rows, columns;

int solve(int r, int c){
	int &a = memo[r][c];
	if(a != -1)
		return a;

	a = 0;
	for(int k = 0; k < 4; k++){
		if(r + dr[k] < 0 || r + dr[k] >= rows || c + dc[k] < 0 || c + dc[k] >= columns)
			continue;
		if(grid[r + dr[k]][c + dc[k]] >= grid[r][c])
			continue;
		a = max(a, 1 + solve(r + dr[k], c + dc[k]));
	}
	return a;
}

int main(){
	int casos;
	cin >> casos;
	while(casos--){
		string name;
		cin >> name >> rows >> columns;

		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				scanf("%d", &grid[i][j]);

		ans = -1;

		memset(memo, -1, sizeof memo);

		for(int i = 0; i < rows; i++)
			for(int j = 0; j < columns; j++)
				ans = max(ans, solve(i, j));

		printf("%s: %d\n", name.c_str(), ans + 1);
	}
}