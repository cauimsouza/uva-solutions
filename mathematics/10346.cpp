#include <stdio.h>

int main(){
	int n, k;
	while(scanf("%d %d", &n, &k) != EOF){
		int quoc, resto;
		int sum = 0;
		while(n){
			quoc = n / k;
			resto = n % k;
			if(!quoc){
				sum += resto;
				break;
			}
			sum += quoc * k;
			n = resto + quoc;
		}
		printf("%d\n", sum);
	}

	return 0;
}