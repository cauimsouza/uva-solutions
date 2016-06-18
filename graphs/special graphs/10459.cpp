#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

using ii = pair<int, int>;
using vi = vector<int>;

vector<vi> adj_list;
vi dist, dfs_num, best;
int furthest;

void dfs(int v){
	for(int i = 0; i < (int) adj_list[v].size(); i++){
		int u = adj_list[v][i];
		if(dist[u] < 0){
			dist[u] = dist[v] + 1;
			furthest = max(furthest, dist[u]);
			dfs(u);
		}
	}
}

int findBest(int en, int v){
	dfs_num[v] = 1;
	if(v == en)
		return 1;
	int ans = INF;
	for(int i = 0; i < (int) adj_list[v].size(); i++){
		int u = adj_list[v][i];
		if(dfs_num[u])
			continue;
		ans = min(ans, findBest(en, u));
		if(ans < 1e4){
			if((furthest % 2  == 1 && (ans == furthest / 2 || (ans - 1) == furthest / 2)) || (furthest % 2 == 0 && ans == furthest / 2))
				best.push_back(v);
			return ans + 1;
		}
	}
	return INF;
}

int main(){
	int n;

	while(scanf("%d", &n) != EOF){
		adj_list.assign(n, vi());

		for(int i = 0; i < n; i++){
			int num;
			scanf("%d", &num);
			while(num--){
				int v;
				scanf("%d", &v);
				adj_list[i].push_back(v - 1);
			}
		}

		vi worst, worst_roots, checked(n, 0);
		best.clear();
		dist.assign(n, -1);
		dist[0] = furthest = 0;
		dfs(0);
		for(int i = 0; i < n; i++)
			if(dist[i] == furthest){
				worst.push_back(i);
				worst_roots.push_back(i);
			}

		while(!worst.empty()){
			int u = worst.back();
			worst.pop_back();
			if(checked[u])
				continue;
			checked[u] = 1;

			dist.assign(n, -1);
			dist[u] = furthest = 0;
			dfs(u);
			for(int i = 0; i < n; i++)
				if(dist[i] == furthest){
					worst.push_back(i);
					worst_roots.push_back(i);

					dfs_num.assign(n, 0);
					findBest(i, u);
				}
		}	

		sort(best.begin(), best.end());
		sort(worst_roots.begin(), worst_roots.end());
		best.resize(unique(best.begin(), best.end()) - best.begin());
		worst_roots.resize(unique(worst_roots.begin(), worst_roots.end()) - worst_roots.begin());

		printf("Best Roots  :");
		for(int i = 0; i < (int) best.size(); i++)
			printf(" %d", best[i] + 1);
		printf("\nWorst Roots :");
		for(int i = 0; i < (int) worst_roots.size(); i++)
			printf(" %d", worst_roots[i] + 1);
		printf("\n");
	}
}