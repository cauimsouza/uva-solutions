#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

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
	int tests;
	cin >> tests;
	for (int test = 0; test < tests; ++test){
		int vertices, edges, airCost;
		scanf("%d %d %d", &vertices, &edges, &airCost);

		UnionFind UF(vertices);
		vector< pair<int, pair<int,int> > > edgeList;

		for(int i = 0; i < edges; i++){
			int loca, locb, cost;
			scanf("%d %d %d", &loca, &locb, &cost);
			edgeList.push_back(make_pair(cost, make_pair(loca - 1, locb - 1)));
		}
		sort(edgeList.begin(), edgeList.end());

		int totalCost = 0;
		int i = 0;
		while(i < edges && UF.numOfSets() > 1){
			int loca, locb, cost;
			auto iii = edgeList[i++]; 
			cost = iii.first;
			loca = iii.second.first;
			locb = iii.second.second;

			if(cost >= airCost)
				break;
			if(UF.isSameSet(loca, locb))
				continue;
			UF.unionSet(loca, locb);
			totalCost += cost;
		}
		totalCost += UF.numOfSets() * airCost;

		printf("Case #%d: %d %d\n", test + 1, totalCost, UF.numOfSets());
	}
}