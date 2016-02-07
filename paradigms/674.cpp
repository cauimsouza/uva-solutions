#include <bits/stdc++.h>
using namespace std;

int type[5] = {1,5,10,25,50};
long long memo[10][7500];

int ways(int id, int value){
	if(value == 0) return 1;
	if(id >= 5 || value < 0) return 0;
	if(memo[id][value] != -1) return memo[id][value];
	return memo[id][value] = ways(id + 1, value) + ways(id, value - type[id]);
}

int main(){
	memset(memo, -1, sizeof memo);
	int a;
	while(scanf("%d", &a) != EOF){
		printf("%d\n", ways(0,a));
	}
}