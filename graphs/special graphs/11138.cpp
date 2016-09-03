#include <cstdio>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

vvi adjList;
vi match, vis;

int Aug(int u){
	if(vis[u]) return 0;
	vis[u] = 1;
	for(int i = 0; i < (int)adjList[u].size(); i++){
		int v = adjList[u][i];
		if(match[v] == -1 || Aug(match[v])){
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main(){
	int cases;
	scanf("%d", &cases);
	for (int caseno = 0; caseno < cases; ++caseno)
	{
		int nuts, bolts;
		scanf("%d %d", &nuts, &bolts);

		adjList.assign(nuts, vi());
		for(int i = 0; i < nuts; i++){
			for(int j = 0; j < bolts; j++){
				int x;
				scanf("%d", &x);
				if(x)
					adjList[i].push_back(j);
			}
		}

		match.assign(bolts, -1);
		int MCBM = 0;
		for(int i = 0; i < nuts; i++){
			vis.assign(nuts + bolts, 0);
			MCBM += Aug(i);
		}

		printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", caseno + 1, MCBM);
	}
	
	return 0;
}