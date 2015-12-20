#include <bits/stdc++.h>
using namespace std;

int A[10][10];

int main(int argc, char const *argv[])
{
	char c;
	int i, j, k; // linha, coluna
	while(scanf(" %c", &c) != EOF){
		i = 8; j = 1;

		if(isdigit(c)){
			while(c-- - '0'){
				A[i][j] = '.';
				j++;
			}
		}
		else{
			A[i][j] = c;
			j++;
		}

		while((c = getchar()) != '\n'){
			if(isdigit(c)){
				while(c-- - '0'){
					A[i][j] = '.';
					j++;;
				}
			}
			else if(isalpha(c)){
				A[i][j] = c;
				j++;
			}
			else{
				i--;
				j = 1;
			}
		}

		int cont = 0;
		bool atacado;
		for (int i = 1; i <= 8; ++i)
		{
			for (int j = 1; j <= 8; ++j)
			{
				if(A[i][j] == '.'){
					atacado = false;

					for(k = j+1; k <= 8 && A[i][k] == '.'; k++);
					if(k <= 8)	if(A[i][k] == 'r' || A[i][k] == 'R' || A[i][k] == 'q' || A[i][k] == 'Q' || (k == j+1 && (A[i][k] == 'k' || A[i][k] == 'K')))
						atacado = true;

					for(k = j-1; !atacado && k >= 1 && A[i][k] == '.'; k--);
					if(k >= 1)	if(A[i][k] == 'r' || A[i][k] == 'R' || A[i][k] == 'q' || A[i][k] == 'Q' || (k == j-1 && (A[i][k] == 'k' || A[i][k] == 'K')))
						atacado = true;

					for(k = i+1; !atacado && k <= 8 && A[k][j] == '.'; k++);
					if(k <= 8)	if(A[k][j] == 'r' || A[k][j] == 'R' || A[k][j] == 'q' || A[k][j] == 'Q' || (k == i+1 && (A[k][j] == 'k' || A[k][j] == 'K')))
						atacado = true;

					for(k = i-1; !atacado && k >= 1 && A[k][j] == '.'; k--);
					if(k >= 1)	if(A[k][j] == 'r' || A[k][j] == 'R' || A[k][j] == 'q' || A[k][j] == 'Q' || (k == i-1 && (A[k][j] == 'k' || A[k][j] == 'K')))
						atacado = true;

					for(k = 1; !atacado && i+k <= 8 && j+k <= 8 && A[i+k][j+k] == '.'; k++);
					if(i+k <= 8 && j+k <= 8)	if(A[i+k][j+k] == 'b' || A[i+k][j+k] == 'B' || A[i+k][j+k] == 'q' || A[i+k][j+k] == 'Q' || (k == 1 && (A[i+k][j+k] == 'k' || A[i+k][j+k] == 'K' || A[i+k][j+k] == 'p')))
						atacado = true;

					for(k = 1; !atacado && i-k >= 1 && j-k >= 1 && A[i-k][j-k] == '.'; k++);
					if(i-k >= 1 && j-k >= 1)	if(A[i-k][j-k] == 'b' || A[i-k][j-k] == 'B' || A[i-k][j-k] == 'q' || A[i-k][j-k] == 'Q' || (k == 1 && (A[i-k][j-k] == 'k' || A[i-k][j-k] == 'K' || A[i-k][j-k] == 'P')))
						atacado = true;

					for(k = 1; !atacado && i+k <= 8 && j-k >= 1 && A[i+k][j-k] == '.'; k++);
					if(i+k <= 8 && j-k >= 1)	if(A[i+k][j-k] == 'b' || A[i+k][j-k] == 'B' || A[i+k][j-k] == 'q' || A[i+k][j-k] == 'Q' || (k == 1 && (A[i+k][j-k] == 'k' || A[i+k][j-k] == 'K' || A[i+k][j-k] == 'p')))
						atacado = true;

					for(k = 1; !atacado && i-k >= 1 && j+k <= 8 && A[i-k][j+k] == '.'; k++);
					if(i-k >= 1 && j+k <= 8)	if(A[i-k][j+k] == 'b' || A[i-k][j+k] == 'B' || A[i-k][j+k] == 'q' || A[i-k][j+k] == 'Q' || (k == 1 && (A[i-k][j+k] == 'k' || A[i-k][j+k] == 'K' || A[i-k][j+k] == 'P')))
						atacado = true;

					if(!atacado && i+2 <= 8 && j+1 <= 8 && (A[i+2][j+1] == 'n' || A[i+2][j+1] == 'N'))
						atacado = true;

					if(!atacado && i+2 <= 8 && j-1 >= 1 && (A[i+2][j-1] == 'n' || A[i+2][j-1] == 'N'))
						atacado = true;

					if(!atacado && i-2 >= 1 && j+1 <= 8 && (A[i-2][j+1] == 'n' || A[i-2][j+1] == 'N'))
						atacado = true;

					if(!atacado && i-2 >= 1 && j-1 >= 1 && (A[i-2][j-1] == 'n' || A[i-2][j-1] == 'N'))
						atacado = true;

					if(!atacado && i+1 <= 8 && j+2 <= 8 && (A[i+1][j+2] == 'n' || A[i+1][j+2] == 'N'))
						atacado = true;

					if(!atacado && i+1 <= 8 && j-2 >= 1 && (A[i+1][j-2] == 'n' || A[i+1][j-2] == 'N'))
						atacado = true;

					if(!atacado && i-1 >= 1 && j+2 <= 8 && (A[i-1][j+2] == 'n' || A[i-1][j+2] == 'N'))
						atacado = true;

					if(!atacado && i-1 >= 1 && j-2 >= 1 && (A[i-1][j-2] == 'n' || A[i-1][j-2] == 'N'))
						atacado = true;

					if(!atacado){	
						cont++;
					}
				}

			}
		}

		printf("%d\n", cont);

	}

	return 0;
}
