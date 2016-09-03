#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 105;

using vi = vector<int>;
using vvi = vector<vi>;

vvi adjList;
vi match;
vi vis;

int Aug(int u){
	if(vis[u]) return 0;
	vis[u] = 1;
	for(int i = 0; i < (int)adjList[u].size(); i++){
		int v = adjList[u][i];
		if(match[v] == -1 || Aug(match[v]) == 1){
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main(){
	int tests;
	scanf("%d", &tests);
	int num[MAX];
	for (int caseno = 0; caseno < tests; ++caseno)
	{
		int left, right;
		scanf("%d", &right);
		
		for(int i = 0; i < right; i++)
			scanf("%d", &num[i]);

		scanf("%d", &left);
		adjList.assign(left, vi());
		for(int i = 0; i < left; i++){
			int x;
			scanf("%d", &x);
			for(int j = 0; j < right; j++){
				if((num[j] != 0 && x % num[j] == 0) || (num[j] == 0 && x == 0)){
					adjList[i].push_back(j);
				}
				
			}
		}

		match.assign(right, -1);
		int MCBM = 0;
		for(int i = 0; i < left; i++){
			vis.assign(left, 0);
			MCBM += Aug(i);
		}

		printf("Case %d: %d\n", caseno + 1, MCBM);
	}
	
	return 0;
}