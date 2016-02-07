#include <bits/stdc++.h>
using namespace std;

int main(){

	int A[40][30];
	int N, t, count = 0;
	while(scanf("%d%d", &N, &t)){
		if(N == 0 && t == 0) break;
		// reseting the array A
		for (int i = 0; i < 40; ++i) {
			for(int j = 0; j < 30; j++)
				A[i][j] = 0; }

		// reading the number of customers in each area
		for(int i = 0; i < N; i++){
			A[i][i+1] = 1;
			scanf("%d", &A[i][0]);
		}

		//reading the commom service areas
		int commomAreas, idx = N;
		scanf("%d", &commomAreas);
		for(int i = 0; i < commomAreas; i++){
			int t;
			scanf("%d", &t);
			for(int i = 0; i < t; i++){
				int id;
				scanf("%d", &id);
				A[idx][id] = 1;
			}
			scanf("%d", &A[idx][0]);
			for(int i = 1; i <= N; i++)
				if(A[idx][i]) A[i-1][0] -= A[idx][0];
			idx++;
		}
		//for(int i = 0; i < idx; i++){for(int j = 0; j <= N; j++) printf("%d ", A[i][j]);printf("\n");}
		// iterating through each permutation and computing the max number of customers
		bool *perm = new bool[N];
		bool *copy = new bool[N];
		for(int i = 0; i < N; i++) perm[i] = copy[i] = 0;
		for(int i = 0; i < t; i++) perm[i] = copy[i] = 1;
		long long maxSum = -1;
		do{
			long long sum = 0;
			for(int i = 0; i < 40; i++){
				for(int j = 1; j < 30; j++){
					if(A[i][j] && perm[j-1]){
						sum += A[i][0] > 0 ? A[i][0] : 0;
						break;
					}
				}
			}
			if(sum > maxSum){
				maxSum = sum;
				for(int i = 0; i < N; i++) copy[i] = perm[i];
			}
		}while(prev_permutation(perm, perm + N));

		printf("Case Number  %d\n", ++count);
		printf("Number of Customers: %lld\n", maxSum);
		printf("Locations recommended:");
		for(int i = 0; i < N; i++)
			if(copy[i]) printf(" %d", i + 1);
		printf("\n\n");

		delete[]perm;
		delete[]copy;
	}

	return 0;
}