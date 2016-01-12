#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main(int argc, char const *argv[])
{
	int n, queries;
	while(scanf("%d", &n), n){
		scanf("%d", &queries);
		vi num(n+10);

		int i = 1, prevValue, nextValue;
		scanf("%d", &prevValue);
		for (int j = 2; j <= n; ++j)
		{
			scanf("%d", &nextValue);
			if(prevValue != nextValue){
				while(i < j) num[i++] = j;
			}
			prevValue = nextValue;
		}
		while(i <= n) num[i++] = n + 1;

		int a, b, max = 0, j, interval;
		while(queries--){
			scanf("%d %d", &a, &b);
			j = a;
			max = 0;
			while(j <= n && j <= b){
				interval = min(num[j],b+1) - j;
				max = (max > interval ? max : interval);
				j = num[j];
			}
			printf("%d\n", max);
		}
	}

	return 0;
}
