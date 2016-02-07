#include <bits/stdc++.h>
using namespace std;

const int MAXD = 210;
const int MAXC = 1500;
const int MAXN = 25;
int n, x, t, k;
int price[MAXD]; // price of each dim sum
int flavour[MAXD]; // total flavour of each dim sum
int memo[MAXD][MAXC][MAXN];

inline bool estoura(int cash){
	return (cash + (n + 1) * t) * 11 > x * (n + 1) * 10;
}

int val(int id, int cash, int qnt){
	if(qnt >= 2 * (n + 1) || id >= 2 * k) return 0; // we bought to many dim sums or there are no more options
	int &a = memo[id][cash][qnt];
	if(a != -1) return a;
	if(estoura(cash + price[id])) return a = val(id + 1, cash, qnt);
	return a = max(val(id + 1, cash, qnt), flavour[id] + val(id + 1, cash + price[id], qnt + 1));
}

int main(){
	while(scanf("%d %d %d %d", &n, &x, &t, &k), n){
		for(int i = 0; i < k; i++){
			scanf("%d", &price[i]);
			price[k+i] = price[i];
			flavour[i] = flavour[k+i] = 0;
			for(int j = 1; j <= n + 1; j++){
				int x;
				scanf("%d", &x);
				flavour[i] += x;
				flavour[k+i] += x; 
			}
		}

		memset(memo, -1, sizeof memo);
		int ans = val(0, 0, 0);
		printf("%.2f\n", ans/(1.0 * (n + 1)));
	}
}