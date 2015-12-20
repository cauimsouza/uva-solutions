#include <bits/stdc++.h>
using namespace std;



int main(int argc, char const *argv[])
{
	int maior, menor, cont;
	int linhas, colunas;
	
	while(scanf("%d%d", &linhas, &colunas), linhas || colunas){
		maior = max(linhas, colunas);
		menor = min(linhas, colunas);
		if(menor >= 3)
			cont = ((colunas+1)/2)* ((linhas+1)/2) + (colunas/2)*(linhas/2);
		else if(menor == 2){
			if(maior%4 == 0) cont = (maior/4) * 4;
			else if(maior%4 == 1) cont = (maior/4) * 4 + 2;
			else cont = (maior/4)*4 + 4;
		}
		else if(menor == 1)
			cont = maior;
		else
			cont = 0;
		
		
		printf("%d knights may be placed on a %d row %d column board.\n", cont, linhas, colunas);
	}

	return 0;
}
