#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <map>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using iii= pair<int, ii>;

class UnionFind{
	vi p, level;
	int sets;
public:
	UnionFind(int N){
		p.resize(N);
		level.resize(N);
		sets = N;
		for(int i = 0; i < N; i++){
			p[i] = i;
			level[i] = 0;
		}
	}
	int findSet(int i){
		if(i == p[i])
			return i;
		return p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSets(int i, int j){
		int x = findSet(i), y = findSet(j);
		if(x == y)
			return;
		sets--;
		if(level[x] > level[y]){
			p[y] = x;
			return;
		}
		p[x] = y;
		if(level[x] == level[y])
			level[y]++;

	}
	int numSets(){
		return sets;
	}
};

int main(){

#ifndef ONLINE_JUDGE
	freopen("entrada","r",stdin);
#endif

	int v, e;
	map<string,int> names;
	vector<iii> edges;
	while(scanf("%d %d", &v, &e), v){
		
		for(int i = 0; i < v; i++){
			string nome;
			cin >> nome;
			names[nome] = i;
		}

		edges.clear();
		for(int i = 0; i < e; i++){
			string cityA, cityB;
			int peso;
			cin >> cityA >> cityB >> peso;
			int idA = names[cityA], idB = names[cityB];
			edges.push_back(make_pair(peso, ii(idA, idB)));
		}
		string lixo;
		cin >> lixo;

		sort(edges.begin(), edges.end());

		UnionFind uf(v);
		int mst = 0;
		int num = v;
		for(int i = 0; i < e && v > 1; i++){
			int va = edges[i].second.first, vb = edges[i].second.second, w = edges[i].first;
			if(uf.isSameSet(va, vb))
				continue;
			v--;
			mst += w;
			uf.unionSets(va, vb);
		}

		if(v > 1)
			printf("Impossible\n");
		else
			printf("%d\n", mst);
	}
}
