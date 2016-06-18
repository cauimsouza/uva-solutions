#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vector<vi> adj_list;
vi morte, dfs_num, topo_sort, ways;

void dfs(int u){
	dfs_num[u] = 1;
	for(int i  = 0; i < (int) adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(dfs_num[v] == 0)
			dfs(v);
	}
	topo_sort.push_back(u);
}

int main(){
	int events, k = 0;
	while(scanf("%d", &events) != EOF){
		adj_list.assign(events, vi());
		morte.clear();

		for(int i = 0; i < events; i++){
			int num_arestas;
			scanf("%d", &num_arestas);

			if(num_arestas == 0)
				morte.push_back(i);

			while(num_arestas--){
				int vert;
				scanf("%d", &vert);
				adj_list[i].push_back(vert);
			}
		}

		topo_sort.clear();
		dfs_num.assign(events, 0);
		for(int i = 0; i < events; i++){
			if(dfs_num[i] == 0)
				dfs(i);
		}

		ways.assign(events, 0);
		ways[0] = 1;
		for(int i = events - 1; i >= 0; i--){
			int u = topo_sort[i];
			for(int j = 0; j < (int)adj_list[u].size(); j++){
				int v = adj_list[u][j];
				ways[v] += ways[u];
			}
		}

		int sum = 0;
		for(auto it = morte.begin(); it != morte.end(); it++ )
			sum += ways[*it];

		if(k++)
			printf("\n");
		printf("%d\n", sum);
	}
}