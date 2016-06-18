#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

int dfs_counter, rootChildren, root;
vector<bool> artPoint;
vector< vi > adjList;
vi dfs_num;
vi dfs_low;
vi path;

void tarjan(int u){
	dfs_low[u] = dfs_num[u] = dfs_counter++; // dfs_low[u] <= dfs_num[u]

	for(int i = 0; i < (int) adjList[u].size(); i++){
		int v = adjList[u][i];

		// vertex v was just discovered
		if(dfs_num[v] == 0){
			path[v] = u;

			if(u == root)
				rootChildren++;

			tarjan(v);
			
			// tree rooted at vertex v cannot reach a parent of vertex u
			if(dfs_low[v] >= dfs_num[u])
				artPoint[u] = 1;

			// update dfs_low[u]
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}

		else if(path[u] != v)
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main(){
	int numLocals;
	int k = 1;
	while(scanf("%d", &numLocals), numLocals){
		adjList.assign(numLocals, vi() );
		vector<string> names;

		for(int i = 0; i < numLocals; i++){
			string name;
			cin >> name;
			names.push_back(name);
		}

		int numLinks;
		scanf("%d", &numLinks);
		for(int i = 0; i < numLinks; i++){
			string a, b;
			int ida, idb;
			cin >> a >> b;

			ida = find(names.begin(), names.end(), a) - names.begin();
			idb = find(names.begin(), names.end(), b) - names.begin();
			adjList[ida].push_back(idb);
			adjList[idb].push_back(ida);
		}

		artPoint.assign(numLocals, false);
		dfs_low.assign(numLocals, 0);
		dfs_num.assign(numLocals, 0);
		path.assign(numLocals, -1);
		dfs_counter = 1;
		rootChildren = 0;

		for(int rt = 0; rt < numLocals; rt++){
			if(dfs_num[rt] > 0)
				continue;
			root = rt;
			rootChildren = 0;
			tarjan(rt);
			artPoint[rt] = rootChildren > 1;
		}

		int numArts = 0;
		for(int i = 0; i < numLocals; i++)
			numArts += artPoint[i];

		if(k > 1)
			printf("\n");
		printf("City map #%d: %d camera(s) found\n", k++, numArts);
		vector<string> output;
		for(int i = 0; i < numLocals; i++){
			if(artPoint[i])
				output.push_back(names[i]);
		}
		sort(output.begin(), output.end());
		for(auto it = output.begin(); it != output.end(); it++){
			cout << *it << endl;
		}
	}
}
