#include <bits/stdc++.h>
using namespace std;

#define inf (int)1e8

int n;
int height[100010];

bool can(int k){
	int h = 0;
	for(int i = 0; i < n; i++){
		if(height[i] - h > k) return false;
		if(height[i] - h == k) k--;
		h = height[i];
	}
	return true;
}

int main(){
	int test_cases;
	scanf("%d", &test_cases);
	for (int count = 0; count < test_cases; ++count)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &height[i]);
		int lo = 1, hi = inf, ans, mid;
		while(lo < hi){
			mid = (lo + hi)/ 2;
			if(can(mid)){ hi = ans = mid; }
			else lo = mid + 1;
		}

		printf("Case %d: %d\n", count + 1, ans);
	}
}