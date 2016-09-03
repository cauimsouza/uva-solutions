#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%d", &n), n){
		int sum = 1;
		for(int i = 2; i <= (int)sqrt(n); i++)
			if(!(n % i)) sum += i + n / i;
		if(n == ((int) sqrt(n)) * ((int) sqrt(n))) sum -= (int) sqrt(n);
		printf("%5d  ", n);
		if(sum == n) printf("PERFECT\n");
		else if(sum < n) printf("DEFICIENT\n");
		else printf("ABUNDANT\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}