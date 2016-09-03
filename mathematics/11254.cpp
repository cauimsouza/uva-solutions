#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n)){
		if(n < 0) break;
		int r = sqrt(2 * n);
		for(; r > 0; r--){
			int a = 2 * n + r - r * r;
			if(a % (2*r) == 0){
				a /= 2 * r;
				printf("%d = %d + ... + %d\n", n, a, a + r - 1);
				break;
			}
		}
	}
}