#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000

int main(){

	int t;
	int M[10][10];

	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &M[i][j]);

		int *bob = new int[n];
		for(int i = 0; i < n; i++) bob[i] = i;
		int minSum = inf;
		do{
			int sum = 0;
			for(int i = 0; i < n; i++)
				sum += M[i][ bob[i] ];
			if(sum < minSum) minSum = sum;
		}while(next_permutation(bob, bob + n));

		printf("%d\n", minSum);

		delete[]bob;
	}

	return 0;
}