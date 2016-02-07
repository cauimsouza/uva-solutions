#include <bits/stdc++.h>
using namespace std;

int type[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
long long memo[15][30010];

long long ways(int id, int value){
	if(value == 0) return 1;
	if(id >= 11 || value < 0) return 0;
	if(memo[id][value] != -1) return memo[id][value];
	return memo[id][value] = ways(id + 1, value) + ways(id, value - type[id]);
}

int main(){
	memset(memo, -1, sizeof memo);
	int a, b;
	while(scanf("%d.%d", &a, &b)){
		if(a == 0 && b == 0) break;
		printf("%3d.%02d%17lld\n", a, b, ways(0, 100 * a + b));
	}
}