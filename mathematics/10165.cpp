#include <cstdio>

int main(){
	int n, total, x;
	while(scanf("%d", &n), n){
		total = 0;
		while(n--){
			scanf("%d", &x);
			total ^= x;
		}
		if(total)
			printf("Yes\n");
		else
			printf("No\n");
	}
}