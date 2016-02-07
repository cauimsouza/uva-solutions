#include <bits/stdc++.h>
using namespace std;

const int MAXM = 45;
const int MAXV = 310;
const long long inf = 1e18;
int conValue[MAXM];
int infValue[MAXM];
long long memo[MAXV][MAXV];
int m, s;

inline int compare(int conv, int info){
	long long dif = conv*conv + info*info - s * s;
	if(dif == 0) return 0;
	else if(dif > 0) return 1;
	return -1; 
}

long long change(int conv, int info){
	int comp = compare(conv, info);
	if(comp == 0) return 0;
	if(comp > 0) return inf;
	if(memo[conv][info] != -1) return memo[conv][info];
	long long result = inf;
	for(int i = 0; i < m; i++) result = min(result, 1 + change(conv + conValue[i], info + infValue[i]));
	return memo[conv][info] = result; 
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &m, &s);
		for(int i = 0; i < m; i++) scanf("%d %d", &conValue[i], &infValue[i]);

		memset(memo, -1, sizeof memo);
		long long result = change(0,0);
		if(result >= inf) printf("not possible\n");
		else printf("%lld\n", result);
	}
}