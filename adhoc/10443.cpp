#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int (i) = (a); (i) <= (b); (i)++)

int linhas, colunas;
char **A, **B;

void Copia(){
	REC(i, 1, linhas)
		REC(j, 1, colunas)
			B[i][j] = A[i][j];
}

int main(int argc, char const *argv[])
{
	int t, dias;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &linhas, &colunas, &dias);
		A = new char*[linhas+10];
		B = new char*[linhas+10];

		REC(i, 1, linhas){
			A[i] = new char[colunas+10];
			B[i] = new char[colunas+10];
		}

		REC(i, 1, linhas){
			REC(j, 1, colunas){
				scanf(" %c", &A[i][j]);
			}
		}

		while(dias--){
			Copia();
			REC(i, 1, linhas){
				REC(j, 1, colunas){
					if(B[i][j] == 'R'){
						if(j < colunas && B[i][j+1] == 'P')	A[i][j] = 'P';
						else if(j > 1 && B[i][j-1] == 'P')	A[i][j] = 'P';
						else if(i > 1 && B[i-1][j] == 'P')	A[i][j] = 'P';
						else if(i < linhas && B[i+1][j] == 'P')	A[i][j] = 'P';
					}
					else if(B[i][j] == 'S'){
						if(j < colunas && B[i][j+1] == 'R')	A[i][j] = 'R';
						else if(j > 1 && B[i][j-1] == 'R')	A[i][j] = 'R';
						else if(i > 1 && B[i-1][j] == 'R')	A[i][j] = 'R';
						else if(i < linhas && B[i+1][j] == 'R')	A[i][j] = 'R';
					}
					else{
						if(j < colunas && B[i][j+1] == 'S')	A[i][j] = 'S';
						else if(j > 1 && B[i][j-1] == 'S')	A[i][j] = 'S';
						else if(i > 1 && B[i-1][j] == 'S')	A[i][j] = 'S';
						else if(i < linhas && B[i+1][j] == 'S')	A[i][j] = 'S';
					}
				}
			}
			
		}

		REC(i, 1, linhas){
			REC(j, 1, colunas){
				putchar(A[i][j]);
			}
			putchar('\n');
		}
		if(t)	putchar('\n');

		REC(i, 1, linhas){
			delete[]A[i];
			delete[]B[i];
		}
		delete[]A;
		delete[]B;
	}

	return 0;
}
