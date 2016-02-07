#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vector<vi> AdjList;
int maxBlack, n, sum;
bitset<110> color; // 0 means white, 1 black
bitset<110> Copy; // stores a copy of the optimal solution

void backtracking(int idx){
	if(idx > n){
		if(sum > maxBlack){
			maxBlack = sum;
			for(int i = 1; i <= n; i++) Copy[i] = color[i];
		}
		return;
	}
	bool black = true;
	for(int i = 0; i < (int)AdjList[idx].size(); i++){
		if(color[ AdjList[idx][i] ]){
			black = false;
			break; }
	}
	if(black){ // we may color this vertex black
		color[idx] = 1;
		sum++;
		backtracking(idx + 1);
		color[idx] = 0;
		sum--;
	}
	backtracking(idx + 1);
}

int main(){

	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		int edges;
		scanf("%d%d", &n, &edges);
		maxBlack = sum = 0;
		color.reset();
		Copy.reset();
		AdjList.assign(n + 1, vi());
		for(int i = 1; i <= edges; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			AdjList[a].push_back(b);
			AdjList[b].push_back(a);
		}
		backtracking(1);
		printf("%d\n", maxBlack);
		bool first = true;
		for(int i = 1; i <= n; i++){
			if(Copy[i]){
				if(!first) printf(" ");
				printf("%d", i);
				first = false;
			}
		}
		printf("\n");
	}

	return 0;
}
