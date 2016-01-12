#include <bits/stdc++.h>
using namespace std;

class UnionFind{
	
	vector<int> p, rank, setSize;
	int numSets;
	public:
	UnionFind(int N): p(N), rank(N,0), setSize(N,1), numSets(N)
		{for(int i = 0; i < N; i++) p[i] = i;}
	int findSet(int i){return (i == p[i])? i : (p[i] = findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){ numSets--;
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y]){	p[y] = x; setSize[x] += setSize[y];}
			else{					p[x] = y; setSize[y] += setSize[x];
				if(rank[x] == rank[y]) rank[y]++;}}}
	int numDisjointSets() {return numSets;}
	int sizeOfSet(int i) {return setSize[findSet(i)];}
};

typedef vector<int> vi;

int main()
{
	int n; // numero de casos de teste
	char c;
	scanf("%d\n",&n);
	while(n--){
		UnionFind uf(26);
		char a,b;
		while((c = getchar()) == '('){
			scanf("%c,%c)\n", &a, &b);
			uf.unionSet(a-'A',b-'A');
		}
		while((c = getchar()) != '\n');
		vi vertices;
		
		do{
			scanf("%c%c", &a, &c);
			vertices.push_back(a-'A');
		}while(c == ',');

		int trees = 0, acorns = 0;
		for (int i = 0; i < (int)vertices.size(); ++i)
		{
			if(uf.sizeOfSet(vertices[i]) == 1)	acorns++;
			else if(uf.findSet(vertices[i]) == vertices[i])trees++;
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}

	return 0;
}
