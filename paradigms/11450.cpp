#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC, M, C;
	bool reachable[2][210];
	int price[25][25];
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d", &M, &C);
		memset(reachable, false, sizeof reachable);
		for(int i = 0; i < C; i++){
			scanf("%d", &price[i][0]);
			for(int j = 1; j <= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}

		for(int i = 1; i <= price[0][0]; i++)
			if(M - price[0][i] >= 0) reachable[0][M - price[0][i]] = true;

		int prev = 0, cur = 1;
		for(int g = 1; g < C; g++){
			for(int money = 0; money <= M; money++){
				reachable[cur][money] = 0;
				if(reachable[prev][money]){
					for(int i = 1; i <= price[g][0]; i++)
						if(money - price[g][i] >= 0) reachable[cur][money - price[g][i]] = true;
				}
			}
			swap(prev, cur);
		}

		int money;
		for(money = 0; money <= M && !reachable[prev][money]; money++);
		if(money >= M + 1) printf("no solution\n");
		else printf("%d\n", M - money);
	}
}