#include <bits/stdc++.h>
using namespace std;

const int MAX = 10010;

int main(){
	int n, lis_len, lds_len;
	int A[MAX], lis[MAX], lds[MAX], L[MAX];
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			scanf("%d", &A[i]);
		}

		lis_len = 0;
		for(int i = 0; i < n; i++){
			int pos = lower_bound(L, L + lis_len, A[i]) - L;
			L[pos] = A[i];
			lis[i] = pos + 1;
			lis_len = max(lis_len, pos + 1);
		}

		lds_len = 0;
		for(int i = 0; i < n; i++){
			int pos = lower_bound(L, L + lds_len, A[n-i-1]) - L;
			L[pos] = A[n-i-1];
			lds[i] = pos + 1;
			lds_len = max(lds_len, pos + 1);
		}
		
		int result = 0;
		for(int i = 0; i < n; i++) result = max(result, min(lis[i], lds[n-i-1]));
		printf("%d\n", 2*result-1);
	}
}