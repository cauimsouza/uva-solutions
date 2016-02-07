#include <bits/stdc++.h>
using namespace std;

long long memo[310][310][310];

long long ways(int id, int qnt, int value){
	if(qnt == 0) return value ? 0 : 1;
	if(value == 0 || id > 300 || qnt > value) return 0;
	
	if(memo[id][qnt][value] != -1) return memo[id][qnt][value];
	return memo[id][qnt][value] = ways(id + 1, qnt, value) + ways(id, qnt - 1, value - id);
}

int main(){
	int n;
	memset(memo, -1, sizeof memo);
	while(scanf("%d", &n) != EOF){
		char c;
		c = getchar();

		if(c != '\n'){
			int a;
			scanf("%d", &a);

			c = getchar();
			if(c != '\n'){ // three numbers
				int b;
				scanf("%d", &b);
				long long sum = 0;
				for(int i = a; i <= b; i++) sum += ways(1, i, n);
				cout << sum << endl;
			}
			else{ // only two numbers
				long long sum = 0;
				for(int i = 0; i <= a; i++) sum += ways(1, i, n);
				cout << sum << endl;
			}
		}
		else{ // only one number
			long long sum = 0;
			for(int i = 0; i <= n; i++) sum += ways(1, i, n);
			cout << sum << endl;
		}
	}
}