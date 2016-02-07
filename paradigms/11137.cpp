#include <bits/stdc++.h>
using namespace std;

long long memo[25][10010];

long long ways(int id, int value){
	if(value == 0) return 1;
	if(id >= 21 || value < 0) return 0;
	if(memo[id][value] != -1) return memo[id][value];
	return memo[id][value] = ways(id + 1, value) + ways(id, value - (id + 1)*(id+1)*(id+1));
}

int main(){
	memset(memo, -1, sizeof memo);
	int a;
	while(scanf("%d", &a) != EOF){
		printf("%lld\n", ways(0,a));
	}
}