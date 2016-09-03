#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)){
		if(n < 0)
			break;
		bool sol = false;
		for(int i = sqrt(n) + 2; i > 1; i--){
			int cont = 0;
			int total = n;
			for(int j = 0; j < i; j++){
				if(total % i != 1)
					break;
				cont++;
				total /= i;
				total *= i - 1;
			}
			if(cont == i && total % i == 0){
				printf("%d coconuts, %d people and 1 monkey\n", n, i);
				sol = true;
				break;
			}
		}
		if(!sol)
			printf("%d coconuts, no solution\n", n);
	}
}