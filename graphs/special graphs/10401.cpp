#include <bits/stdc++.h>
using namespace std;

long long memo[20][20];
int n;
string inp;

long long solve(int row, int col){
	if(col == n - 1)
		return 1;
	long long &a = memo[row][col];
	if(a != -1)
		return a;

	if(inp[col + 1] == '?'){
		a = 0;
		for(int i = 0; i < n; i++){
			if(abs(i - row) > 1)
				a += solve(i, col + 1);
		}
	}
	else{
		int nextRow;
		if(isdigit(inp[col + 1]))
			nextRow = inp[col + 1] - '1';
		else
			nextRow = inp[col + 1] - 'A' + 9;

		if(abs(nextRow - row) > 1)
			a = solve(nextRow, col + 1);
		else
			a = 0;
	}
	return a;
}

int main(){
	while(cin >> inp){
		memset(memo, -1, sizeof memo);
		n = inp.length();

		long long ans;
		if(inp[0] != '?'){
			int fRow;
			if(isdigit(inp[0]))
				fRow = inp[0] - '1';
			else
				fRow = inp[0] - 'A' + 9;
			ans = solve(fRow, 0); 
		}
		else{
			ans = 0;
			for(int i = 0; i < n; i++)
				ans += solve(i, 0);
		}

		printf("%lld\n", ans);
	}
}