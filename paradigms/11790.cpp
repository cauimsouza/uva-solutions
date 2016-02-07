#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc, caso = 1;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		vector<int> height(n);
		vector<int> width(n);
		vector<int> lis(n), lds(n);
		for(int i = 0; i < n; i++) scanf("%d", &height[i]);
		for(int i = 0; i < n; i++) scanf("%d", &width[i]); 

		for(int i = 0; i < n; i++){
			lis[i] = width[i];
			lds[i] = width[i];
			for(int j = 0; j < i; j++){
				if(height[j] < height[i] && lis[j] + width[i] > lis[i]){
					lis[i] = lis[j] + width[i];
				}
				else if(height[j] > height[i] && lds[j] + width[i] > lds[i]){
					lds[i] = lds[j] + width[i];
				}
			}
		}

		int lisp = 0, ldsp = 0;
		for(int i = 0; i < n; i++){
			lisp = max(lisp, lis[i]);
			ldsp = max(ldsp, lds[i]);
		}

		printf("Case %d.", caso++);
		if(lisp >= ldsp) printf(" Increasing (%d). Decreasing (%d).\n", lisp, ldsp);
		else printf(" Decreasing (%d). Increasing (%d).\n", ldsp, lisp);		
	}
}