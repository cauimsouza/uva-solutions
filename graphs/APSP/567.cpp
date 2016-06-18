#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1e9;

void zerar(int A[][25]){
	for(int i = 1; i <= 20; i++)
		for(int j = 1; j <= 20; j++)
			A[i][j] = (i == j) ? 0 : INF; 
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("entrada","r",stdin);
#endif

	int dist[25][25];
	int qnt, caso = 1;
	while(scanf("%d", &qnt) == 1){
		zerar(dist);
		while(qnt--){
			int v;
			scanf("%d", &v);
			dist[1][v] = 1;
			dist[v][1] = 1;
		}

		for(int i = 2; i <= 19; i++){
			scanf("%d", &qnt);
			while(qnt--){
				int v;
				scanf("%d", &v);
				dist[i][v] = 1;
				dist[v][i] = 1;
			}
		}

		for(int k = 1; k <= 20; k++)
			for(int i = 1; i <= 20; i++)
				for(int j = 1; j <= 20; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		printf("Test Set #%d\n", caso++);
		int queries;
		scanf("%d", &queries);
		while(queries--){
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%2d to %2d: %d\n", a, b, dist[a][b]);
		}
		printf("\n");
	}
}
