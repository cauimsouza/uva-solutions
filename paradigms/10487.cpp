#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000

int main()
{
	int n, count = 1;
	while(scanf("%d", &n), n){
		int *num = new int[n+10];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &num[i]); }

		sort(num, num + n);

		printf("Case %d:\n", count++);
		int queries;
		scanf("%d", &queries);
		while(queries--){
			int query, diff = inf, sum;
			scanf("%d", &query);

			for(int i = 0; i < n; i++){
				int temp = num[i];
				for(int j = i + 1; j < n; j++){
					if(temp != num[j] && abs(query - temp - num[j]) < diff){
						diff = abs(query - temp - num[j]); sum = temp + num[j]; }
					if(temp != num[j] && temp + num[j] > query) break; 
				}
			}
			printf("Closest sum to %d is %d.\n", query, sum);
		}

		delete[]num;
	}

	return 0;
}