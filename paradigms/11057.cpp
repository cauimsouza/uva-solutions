#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

	int n, prices[10010];
	while(scanf("%d", &n) != EOF){
		for(int i = n; i--; ) scanf("%d", &prices[i]);
		sort(prices, prices + n);

		int m;
		scanf("%d", &m);
		int *lo, *hi, *med;
		lo = hi = lower_bound(prices, prices + n, m/2);
		--hi;
		++lo;
		do{
			med = lo;
			++hi;
			lo = lower_bound(prices, med, m - *hi);
		}while(*lo + *hi - m);
		printf("Peter should buy books whose prices are %d and %d.\n\n", *lo, *hi);
	}

	return 0;
}
