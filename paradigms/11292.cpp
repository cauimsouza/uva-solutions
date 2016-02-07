#include <bits/stdc++.h>
using namespace std;

int main(){
	int d, k;
	int head[20010], height[20010];
	while(scanf("%d%d", &d, &k), d){
		for(int i = 0; i < d; i++) scanf("%d", &head[i]);
		sort(head, head + d);
		for(int i = 0; i < k; i++) scanf("%d", &height[i]);
		sort(height, height+k);

		int i = 0, j = 0, gold = 0;
		while(i < d && j < k){
			while(head[i] > height[j] && j < k) j++;
			if(j == k) break;
			gold += height[j];
			j++;
			i++; 
		}
		if(i == d) printf("%d\n", gold);
		else printf("Loowater is doomed!\n");
	}
}