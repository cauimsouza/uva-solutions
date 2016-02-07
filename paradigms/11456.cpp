#include <bits/stdc++.h>
using namespace std;

const int MAX = 2010;

int main(){
	int tc;
	int peso[MAX], lis[MAX], lds[MAX];
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &peso[i]);

		int result = 0;
		for(int i = n - 1; i >= 0; i--){
			lis[i] = lds[i] = 1;
			for(int j = n - 1; j > i; j--){
				if(peso[j] > peso[i]) lis[i] = max(lis[i], lis[j] + 1);
				if(peso[j] < peso[i]) lds[i] = max(lds[i], lds[j] + 1);
			}
			result = max(result, lis[i] + lds[i] - 1);
		}
		cout << result << endl;
	}
}