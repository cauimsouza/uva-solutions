#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	vector<pair<int,int> > ve;
	while(scanf("%d", &n), n){
		ve.resize(n);
		for(int i = 0; i < n; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			ve[i] = make_pair(a, b);
		}
		sort(ve.begin(),ve.end());

		vector<int> lis(n);
		int result = 0;
		for(int i = 0; i < n; i++){
			lis[i] = 1;
			for(int j = 0; j < i; j++){
				if(ve[j].first <= ve[i].first && ve[j].second <= ve[i].second && lis[j] >= lis[i]){
					lis[i] = lis[j] + 1;
				}
			}
			result = max(result, lis[i]);
		}

		printf("%d\n", result);		
	}
	printf("*\n");
}