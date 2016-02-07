#include <bits/stdc++.h>
using namespace std;

int main(){
	int A[110][110];
	int n;
	while(scanf("%d", &n) != EOF){

		// O(n^2) pre processing
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++){
				scanf("%d", &A[i][j]);
				A[i][j] += j ? A[i][j-1] : 0;
			}

		int sol = -1e9;
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++){
				int sum = 0;
				for(int k = 0; k < n; k++){
					sum += A[k][j] - (i ? A[k][i-1] : 0);
					if(sum > sol) sol = sum;
					if(sum < 0) sum = 0; 
				}
			}

		printf("%d\n", sol);
	}
}