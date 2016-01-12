#include <bits/stdc++.h>
using namespace std;

class UnionFind{
	vector<int> p, rank, setSize;
	int numElements;
	public:
	UnionFind(void): numElements(0) {}
	UnionFind(int N):p(N), rank(N,0), setSize(N,1), numElements(N) {for(int i = 0; i < N; i++)	p[i] = i;}
	int findSet(int i){return (i == p[i]) ? i : (p[i] = findSet(p[i]));}
	bool isSameSet(int i, int j){return findSet(i) == findSet(j);}
	int unionSet(int i, int j){
		int x = findSet(i), y = findSet(j);
		if(!isSameSet(i,j)){ 
			if(rank[x] > rank[y]) {p[y] = x; setSize[x] += setSize[y]; printf("%d\n", setSize[x]);}
			else{				   p[x] = y; setSize[y] += setSize[x]; printf("%d\n", setSize[y]); 
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
		else printf("%d\n", setSize[x]);
	}
	void insertItem(){
		p.push_back(numElements++); // the new element's parent is himself
		rank.push_back(0);
		setSize.push_back(1);
	}
};

int main(int argc, char const *argv[])
{
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		int friendships_formed;
		scanf("%d", &friendships_formed);
		map<string, int> NameList;
		UnionFind uf;

		int count = 0;
		string nome1, nome2;
		for (int i = 0; i < friendships_formed; ++i)
		{
			cin >> nome1 >> nome2;
			if(NameList.find(nome1) == NameList.end()){
				uf.insertItem();
				NameList[nome1] = count++;
			}
			if(NameList.find(nome2) == NameList.end()){
				uf.insertItem();
				NameList[nome2] = count++;
			}
			uf.unionSet( NameList[nome1], NameList[nome2] );
		}
	}

	return 0;
}