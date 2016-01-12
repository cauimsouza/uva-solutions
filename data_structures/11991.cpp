#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(int argc, char const *argv[])
{
	int n, queries;
	while(scanf("%d%d", &n, &queries) != EOF){
		map<int, vi> mapa;
		map<int,vi>::iterator it;

		int num;
		int cont = 1;
		while(n--){
			scanf("%d", &num);
			mapa[num].push_back(cont++);
		}

		int occurence;
		while(queries--){
			scanf("%d %d", &occurence, &num);
			it = mapa.find(num);
			if(it == mapa.end() || it->second.size() < occurence) printf("0\n");
			else printf("%d\n", it->second.at(occurence-1));
		}
	}
	return 0;
}