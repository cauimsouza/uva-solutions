#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

const int INF = 1e9;

int main(){

#ifndef ONLINE_JUDGE
	freopen("entrada","r",stdin);
#endif
	
	int conec;
	int caso = 1;
	map<int,int> id;
	vvi adj_list;

	while(scanf("%d", &conec), conec){
		adj_list.clear();
		id.clear();
		while(conec--){
			int a, b;
			int ida, idb;
			scanf("%d%d", &a, &b);

			map<int,int>:: iterator ita = id.find(a);
			if(ita == id.end()){
				id[a] = adj_list.size();
				ida = adj_list.size();
				adj_list.push_back(vi());
			}
			else
				ida = ita->second;

			map<int,int>:: iterator itb = id.find(b);
			if(itb == id.end()){
				id[b] = adj_list.size();
				idb = adj_list.size();
				adj_list.push_back(vi());
			}
			else
				idb = itb->second;

			adj_list[ida].push_back(idb);
			adj_list[idb].push_back(ida);
		}

		int a, b;
		int v = adj_list.size();
		while(scanf("%d %d", &a, &b), (a || b)){
			vi dist(v, INF);
			int s = id[a];
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			while(!q.empty()){
				int u = q.front();
				q.pop();
				if(dist[u] >= b)
					break;
				for(int i = 0; i < (int) adj_list[u].size(); i++){
					int w = adj_list[u][i];
					if(dist[w] == INF){
						dist[w] = dist[u] + 1;
						q.push(w);
					}
				}
			}

			int cont = 0;
			for(int i = 0; i < v; i++){
				if(dist[i] == INF)
					cont++;
			}

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", caso++, cont, a, b);
		}
	}
}