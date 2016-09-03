#include <vector>
#include <cstdio>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi adjlist;
vi dfs_num;
int dfs_counter;
int first_edge_set;
bool possible;

void dfs(int u){
	dfs_num[u] = dfs_counter;
	if(adjlist[u].size() % 2){ // odd number of edges
		possible = false;
		return;
	}
	if(adjlist[u].size() > 0 && first_edge_set > 0 && first_edge_set != dfs_counter){ // not connected set of edges
		possible = false;
		return;
	}
	for(int i = 0; possible && i < (int)adjlist[u].size(); i++){
		first_edge_set = dfs_counter;
		int v = adjlist[u][i];
		if(!dfs_num[v])
			dfs(v);
	}
}

int main(){
	int v, e;
	while(scanf("%d %d", &v, &e) != EOF){
		adjlist.assign(v, vi());
		for (int i = 0; i < e; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			adjlist[a].push_back(b);
			adjlist[b].push_back(a);
		}

		possible = true;
		dfs_num.assign(v, 0);
		dfs_counter = 0;
		first_edge_set = 0;
		for(int i = 0; i < v; i++){
			if(!dfs_num[i]){
				dfs_counter++;
				dfs(i);
			}
		}

		if(possible && first_edge_set > 0)
			printf("Possible\n");
		else
			printf("Not Possible\n");
	}
}