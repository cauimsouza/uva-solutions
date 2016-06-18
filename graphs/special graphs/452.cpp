#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int vertex_weight[30] = {0};
int incoming_degree[30] = {0};
int dfs_num[30] = {0};
int min_path = INF;
vector< vector<int> > adj_list;
vector<int> topo_sort;

inline int charToint(char);
void toposort(int);
void dfs(int, int);

void solve(){
	char c;
	int weight;

	while(scanf("%c", &c) != EOF && c != '\n'){
		scanf("%d", &weight);
		int vertex = charToint(c);
		vertex_weight[ vertex ] = -weight;
		
		// verifica se ha arestas de entrada
		c = getchar();
		if(c != '\n' && c != EOF){
			while((c = getchar()) != '\n' && c != EOF){
				int vertex_in = charToint(c);
				adj_list[vertex_in].push_back(vertex);
				incoming_degree[vertex]++;
			}
		}
	}

	for(int i = 0; i < 30; i++){
		if(!dfs_num[i] && vertex_weight[i]){
			toposort(i);
		}
	}
	
	for(int i = topo_sort.size() - 1; i >= 0; i--){
		int u = topo_sort[i];
		if(incoming_degree[u] == 0){
			dfs(u, vertex_weight[u]);
		}
	}

	printf("%d\n", -min_path);
}

inline int charToint(char c){
	return c - 'A';
}

void toposort(int u){
	dfs_num[u] = 1;
	for(int i = 0; i < (int) adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(!dfs_num[v])
			toposort(v);
	}
	topo_sort.push_back(u);
}

void dfs(int u, int sum){
	if(!adj_list[u].size()){
		min_path = min(min_path, sum);
		return;
	}
	for(int i = 0; i < (int)adj_list[u].size(); i++){
		int v = adj_list[u][i];
		dfs(v, sum + vertex_weight[v]);
	}
}

int main(){
	int tests;
	scanf("%d\n\n", &tests);
	while(tests--){
		memset(vertex_weight, 0, sizeof vertex_weight);
		memset(incoming_degree, 0, sizeof incoming_degree);
		memset(dfs_num, 0, sizeof dfs_num);
		min_path = INF;
		adj_list.assign(30, vector<int>());
		topo_sort.clear();
		solve();
		if(tests)
			printf("\n");
	}
}