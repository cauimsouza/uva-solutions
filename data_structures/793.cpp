#include <bits/stdc++.h>
using namespace std;

class UnionFind{
	vector<int> p, rank;
	public:
	UnionFind(int N):p(N), rank(N,0){for(int i = 0; i < N; i++)	p[i] = i;}
	int findSet(int i){return (i == p[i]) ? i : (p[i] = findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
	int unionSet(int i, int j){
		int x = findSet(i), y = findSet(j);
		if(!isSameSet(i,j)){
			if(rank[x] > rank[y]) p[y] = x;
			else{				  p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	
	int test_cases, cont_test = 0;
	scanf("%d", &test_cases);
	while(test_cases--){
		if(cont_test++) printf("\n");
		int comps; // num of computers
		scanf("%d", &comps);
		UnionFind UNFDS(comps);

		char operation;
		int a, b; // computers' ids
		int success, failure;
		char garb;
		success = failure = 0;
		while(scanf("%c", &garb) != EOF){
			operation = getchar();
			if(!isalpha(operation)) break;
			scanf("%d %d", &a, &b);
			if(operation == 'c') UNFDS.unionSet(a-1, b-1);
			else if(UNFDS.isSameSet(a-1, b-1))	success++;
			else failure++;
		}
		printf("%d,%d\n", success, failure);
	}

	return 0;
}