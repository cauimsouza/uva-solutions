#include <bits/stdc++.h>
using namespace std;

#define REC(i,a,b) for(int i = int(a); i <= int(b); i++)

char **A, **B;
int N, n;
int cont;

int F1(int a, int b){
	REC(i, 1, n){
		REC(j, 1, n){
			if(A[a+i-1][b+j-1] != B[i][j])	return 0;
		}
	}
	return 1;
}

int F4(int a, int b){
	REC(i, 1, n){
		REC(j, 1, n){
			if(A[a+i-1][b+j-1] != B[j][n-i+1])	return 0;
		}
	}
	return 1;
}

int F3(int a, int b){
	REC(i, 1, n){
		REC(j, 1, n){
			if(A[a+i-1][b+j-1] != B[n-i+1][n-j+1])	return 0;
		}
	}
	return 1;
}

int F2(int a, int b){
	REC(i, 1, n){
		REC(j, 1, n){
			if(A[a+i-1][b+j-1] != B[n-j+1][i])	return 0;
		}
	}
	return 1;
}

int main(){
	
	while(scanf("%d%d", &N, &n), N || n){
		A = new char*[N+10];
		B = new char*[n+10];
		REC(i, 0, N+9)	A[i] = new char[N+10];
		REC(i, 0, n+9)	B[i] = new char[n+10];

		REC(i, 1, N){
			REC(j, 1, N)
				scanf(" %c", &A[i][j]);
		}
		REC(i, 1, n){
			REC(j, 1, n)
				scanf(" %c", &B[i][j]);
		}

		int a, b, c, d;
		a = b = c = d = 0;
		REC(i, 1, N-n+1){
			REC(j, 1, N-n+1){
				a += F1(i,j);
				b += F2(i,j);
				c += F3(i,j);
				d += F4(i,j);if(F4(i,j))	printf("i:%d, j: %d\n", i, j);
			}
		}
		printf("%d %d %d %d\n", a, b, c, d);

		REC(i, 0, N+9)	delete[]A[i];
		REC(i, 0, n+9)	delete[]B[i];
		delete[]A;
		delete[]B;
	}

	return 0;
}
