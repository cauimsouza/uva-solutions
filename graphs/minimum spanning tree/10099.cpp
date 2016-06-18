#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

const int INF = 1e9;

class UnionFind{
	vi p, rank;
	int numSets;
public:
	UnionFind(int n){
		p.resize(n);
		rank.assign(n, 0);
		numSets = n;
		for(int i = 0; i < n; i++)
			p[i] = i;
	}
	int findSet(int i){
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		int x = findSet(i), y = findSet(j);
		if(x != y){
			numSets--;
			if(rank[x] > rank[y]){
				p[y] = x;
			}
			else{
				p[x] = y;
				if(rank[x] == rank[y])
					rank[y]++;
			}
		}
	}
	int numOfSets(){
		return numSets;
	}
};

int main(){
	int vertices, edges, k = 1;
	
	while (scanf("%d %d", &vertices, &edges), vertices){
		UnionFind UF(vertices);
		vector< pair<int, pair<int,int> > > edgeList;

		for(int i = 0; i < edges; i++){
			int loca, locb, cost;
			scanf("%d %d %d", &loca, &locb, &cost);
			edgeList.push_back(make_pair(cost, make_pair(loca - 1, locb - 1)));
		}
		sort(edgeList.begin(), edgeList.end(), greater< pair<int, pair<int,int> > >() );

		int origin, destination, numTourists;
		scanf("%d %d %d", &origin, &destination, &numTourists);

		vector< vii > adjList(vertices);
		int i = 0;
		while(UF.numOfSets() > 1){
			auto iii = edgeList[i++];
			int loca = iii.second.first,
				locb = iii.second.second,
				cost = iii.first;
			if(UF.isSameSet(loca, locb))
				continue;
			UF.unionSet(loca, locb);
			adjList[loca].push_back(ii(locb, cost));
			adjList[locb].push_back(ii(loca, cost));
		}

		queue<ii> q;
		q.push(ii(origin - 1, INF));
		vi dfs_num(vertices, 0);
		dfs_num[origin - 1] = 1;
		while(!q.empty()){
			int u = q.front().first,
				minEdge = q.front().second;
			q.pop();
			if(u == destination - 1){
				printf("Scenario #%d\n", k++);
				minEdge--;
				printf("Minimum Number of Trips = %d\n\n",numTourists / minEdge + ((numTourists % minEdge) ? 1 : 0) );
				break;
			}
			for(int i = 0; i < (int) adjList[u].size(); i++){
				int v = adjList[u][i].first,
					cost = adjList[u][i].second;
				if(dfs_num[v] == 0){
					dfs_num[v] = 1;
					q.push(ii(v, min(minEdge, cost)));
				}
			}
		} 
	}
}