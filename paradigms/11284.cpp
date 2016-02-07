#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n, p;
int dist[60][60];
int operaDif[15];
int operaSt[15];
int memo[15][10000];

int tsp(int last, int mask){
	if(mask == (1 << p) - 1) // we have visited all stores, go home
		return -dist[operaSt[last]][0];
	int &a = memo[last][mask];
	if(a != -1) return a;
	a = -inf;
	for(int i = 1; i < p; i++){
		if(mask & (1 << i))
			continue;
		a = max(a, -dist[operaSt[last]][operaSt[i]] + operaDif[i] + tsp(i, mask | (1 << i)));
	}
	a = max(a, -dist[operaSt[last]][0]);
	return a;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		int m;
		scanf("%d %d", &n, &m);
		n++; // because we'll consider the home itself a store

		// reseting dist matrix
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dist[i][j] = i == j ? 0 : inf;
		
		//reading the roads info
		while(m--){
			int a, b, bills, cents; 
			scanf("%d %d %d.%d", &a, &b, &bills, &cents);
			if(100 * bills + cents < dist[a][b])
				dist[a][b] = dist[b][a] = 100 * bills + cents;
		}

		// reading the operas info
		scanf("%d", &p);
		p++; // as explained above
		operaSt[0] = operaDif[0] = 0;
		for(int i = 1; i < p; i++){
			int a, b;
			scanf("%d %d.%d", &operaSt[i], &a, &b);
			operaDif[i] = 100 * a + b;
		}

		// Floyd-Warshall pre-processing to calculate min dist between stores/home
		for(int k = 0; k < n; k++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

		memset(memo, -1, sizeof memo);
		int result = tsp(0, 1);
		if(result > 0)
			printf("Daniel can save $%d.%02d\n", result/100, result%100);
		else
			printf("Don't leave the house\n");
	}
}