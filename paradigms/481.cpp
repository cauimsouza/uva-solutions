#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;

int main(){
	int L[MAX_N], L_id[MAX_N], A[MAX_N], P[MAX_N];

	int i = 0;
	int lis = 0;
	while(scanf("%d", &A[i]) != EOF){
		int pos = lower_bound(L, L + lis, A[i]) - L;
		L[pos] = A[i];
		L_id[pos] = i;
		if(pos == 0) P[i] = -1;
		else P[i] = L_id[pos - 1];
		if(pos + 1 > lis) lis = pos + 1;
		i++;
	}
	
	printf("%d\n-\n", lis);
	i = L_id[lis - 1];
	stack<int> pilha;
	while(i >= 0){
		pilha.push(A[i]);
		i = P[i];
	}

	while(!pilha.empty()){
		printf("%d\n", pilha.top());
		pilha.pop();
	}
}