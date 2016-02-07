#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int vetor[n+5];
	int estudante[25];
	int lis[25];
	for(int i = 0; i < n; i++){
		scanf("%d", &vetor[i]);
	}

	int x;
	while(scanf("%d", &x) != EOF){
		estudante[vetor[0] - 1] = x;
		for(int i = 1; i < n; i++){
			scanf("%d", &x);
			estudante[vetor[i] - 1] = x;
		}

		
		for(int i = 0; i < n; i++){
			lis[i] = 1;
			for(int j = 0; j < i; j++)
				if(estudante[j] < estudante[i]) lis[i] = max(lis[i], lis[j] + 1);
		}

		int resp = 0;
		for(int i = 0; i < n; i++)
			resp = max(resp, lis[i]);

		printf("%d\n", resp);
	}
}