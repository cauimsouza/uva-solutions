#include <cstdio>
#include <cstdlib>

#define MAX 1000000

int prime_fat[MAX + 10];

int main(){
	for(int i = 2; i <= MAX; i++)
		if(prime_fat[i] == 0){
			for(int j = i; j <= MAX; j += i)
				prime_fat[j]++;
		}

	int n;
	while(scanf("%d", &n), n){
		printf("%d : %d\n", n, prime_fat[n]);
	}
}