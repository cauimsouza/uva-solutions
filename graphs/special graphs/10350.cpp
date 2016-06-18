#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int INF = 1e9;

int tempo[125][20][20]; // [andar]/buraco/buraco de cima
int memo[125][20];
int n, m;

int solve(int f, int h){
	if(f == n - 1)
		return 0;
	int &a = memo[f][h];
	if(a != -1)
		return a;
	a = INF;
	for(int i = 0; i < m; i++)
		a = min(a, 2 + tempo[f][h][i] + solve(f + 1, i));
	return a;
}

int main(){
	string nome;
	while(cin >> nome){
		scanf("%d %d", &n, &m);
		
		for(int i = 0; i < n - 1; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < m; k++)
					scanf("%d", &tempo[i][j][k]);
			}
		}

		memset(memo, -1, sizeof memo);
		int ans = solve(0, 0);
		for(int i = 1; i < m; i++)
			ans = min(ans, solve(0, i));

		printf("%s\n%d\n", nome.c_str(), ans);
	}
}