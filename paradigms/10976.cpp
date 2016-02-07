#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	while(scanf("%d", &k) != EOF){
		int count = 0;
		for(int y = k + 1; y <=  2 * k; y++){
			if((k*y)%(y - k) == 0) count++;
		}
		printf("%d\n", count);
		for(int y = k + 1; y <=  2 * k; y++){
			if((k*y)%(y - k) == 0) printf("1/%d = 1/%d + 1/%d\n", k, (k*y)/(y - k), y);
		}
	}

	return 0;
}