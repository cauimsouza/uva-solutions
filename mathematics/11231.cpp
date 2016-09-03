#include <cstdio>

int aux(int n, int m){
	int a = (m % 2) ? (m - 8 + 1) / 2 : (m + 2 - 8) / 2,
		b = (n % 2) ? (n + 1 - 8) / 2 : (n + 2 - 8) / 2;
	if(a < 0 || b < 0) a = 0;
	return a * b;
}

int main(){
	int n, m, c;
	while(scanf("%d %d %d", &n, &m, &c) , n){
		if(c)
			printf("%d\n", aux(n, m) + aux(n - 1, m - 1));
		else
			printf("%d\n", aux(n - 1, m) + aux(n, m - 1));
	}
}