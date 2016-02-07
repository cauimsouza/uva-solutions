#include <bits/stdc++.h>
using namespace std;

int memo[25][110], weight[25];
int n;

bool divide(int sc, int remW){
	if(remW == 0) return true;
	if(sc >= n) return false;
	if(memo[sc][remW] != -1) return memo[sc][remW];
	return memo[sc][remW] = divide(sc + 1, remW) || divide(sc + 1, remW - weight[sc]);
}

void solve(){
	memset(memo, -1, sizeof memo);
	string line;
	stringstream ss;
	getline(cin, line);
	ss << line;
	int sum = 0;
	n = 0;
	while(ss >> weight[n])
		sum += weight[n++];

	if(sum%2 || !divide(0, sum/2))
		printf("NO\n");
	else
		printf("YES\n");

}

int main(){
	int tc;
	scanf("%d\n", &tc);
	while(tc--)
		solve();
}