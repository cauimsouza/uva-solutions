#include <bits/stdc++.h>
using namespace std;

bitset<40> primes;
void SetPrimes(){
	primes.set();
	primes[0] = primes[1] = 0;
	for(int i = 2; i < 40; i++){
		if(primes[i]){
			for(int j = i*i; j < 40; j += i) primes[j] = 0;
		}
	}
}

int n, bitmask;
int numeros[20];
void backtracking(int i){
	if(i >= n){
		if(primes[ numeros[n-1] + numeros[0] ]){
			printf("%d", numeros[0]);
			for(int i = 1; i < n; i++) printf(" %d", numeros[i]);
			printf("\n"); }
		return;
	}
	for(int j = 2; j <= n; j++){
		if(!(bitmask & (1 << j) ) && primes[ numeros[i - 1] + j]){
			numeros[i] = j;
			bitmask |= 1 << j;
			backtracking(i + 1);
			bitmask ^= 1 << j;
		}
	}
}

int main(){
	SetPrimes();
	numeros[0] = 1;
	int count = 0;

	while(scanf("%d", &n) != EOF){
		if(count++) printf("\n");
		printf("Case %d:\n", count);
		bitmask = 2; // 1 << 1
		backtracking(1);
	}

	return 0;
}