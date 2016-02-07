#include <bits/stdc++.h>
using namespace std;

int value[105];
int memo[105][50005];
int m;

int val(int id, int rem){
	if(id == m || rem == 0) return 0;
	int &ans = memo[id][rem];
	if(ans != -1) return ans;
	if(value[id] > rem) return ans = val(id + 1, rem);
	return ans = max(val(id + 1, rem), value[id] + val(id + 1, rem - value[id]));
}

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d", &m);
		int totalSum = 0;
		for(int i = 0; i < m; i++){
			scanf("%d", &value[i]);
			totalSum += value[i];
		}

		memset(memo, -1, sizeof memo);
		int p1 = val(0,totalSum/2);
		int p2 = totalSum - p1;
		printf("%d\n", abs(p1 - p2));
	}
}