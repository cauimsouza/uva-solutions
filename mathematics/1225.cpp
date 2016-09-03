#include <cstdio>
#include <cstring>
using namespace std;

int digitos[10000][10];

void solve(int n){
	if(digitos[n][0] != -1)
		return;
	solve(n - 1);
	for(int i = 0; i < 10; i++)
		digitos[n][i] = digitos[n-1][i];
	int m = n;
	while(m){
		digitos[n][m % 10]++;
		m /= 10;
	}
}

int main(){
	int casos;
	scanf("%d", &casos);
	memset(digitos, -1, sizeof digitos);
	for(int i = 2; i < 10; i++)
		digitos[1][i] = 0;
	digitos[1][0] = 0;
	digitos[1][1] = 1;
	while(casos--){
		int n;
		scanf("%d", &n);
		solve(n);
		printf("%d", digitos[n][0]);
		for(int i = 1; i < 10; i++)
			printf(" %d", digitos[n][i]);
		printf("\n");
	}

	return 0;
}