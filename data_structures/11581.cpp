#include <bits/stdc++.h>
using namespace std;

#define REC(i,a,b) for(int i = int(a); i <= int(b); i++)

int A[5][5], B[5][5];

int main(){
	for(int i = 0; i <= 4; i++){
		A[i][0] = A[0][i] = A[4][i] = A[i][4] = B[i][0] = B[0][i] = B[4][i] = B[i][4] = 0;
	}
	int t, par, cont;
	bool nula;
	char c;

	scanf("%d", &t);
	while(t--){
		for (int i = 1; i <= 3; ++i)
		{
			for(int j = 1; j <= 3; j++){
				scanf(" %c", &c);
				if(c == '1'){
					A[i][j] = 1;
					nula = false;
				}
				else A[i][j] = 0;
			}
		}
		par = 1;
		cont = -1;
		while(!nula){
			cont++;
			if(par%2){ // A -> B
				nula = true;
				REC(i, 1, 3){
					REC(j, 1, 3){
						B[i][j] = (A[i-1][j] + A[i+1][j] + A[i][j-1] + A[i][j+1])%2;
						if(B[i][j])	nula = false;
					}
				}
			}
			else{ // B->A
				nula = true;
				REC(i, 1, 3){
					REC(j, 1, 3){
						A[i][j] = (B[i-1][j] + B[i+1][j] + B[i][j-1] + B[i][j+1])%2;
						if(A[i][j])	nula = false;
					}
				}
			}
			par++;
		}
		printf("%d\n", cont);
	}

	return 0;
}
