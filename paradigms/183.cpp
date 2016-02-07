#include <bits/stdc++.h>
using namespace std;

int linhas, colunas, charsonline;
char type = '0';
char A[210][210];

void BtoD(int linha, int qtdelinha, int col, int qtdecol){
	if(qtdelinha <= 0 || qtdecol <= 0) return;
	bool um = false, zero = false;
	for(int i = linha; i < linha + qtdelinha; i++){
		for(int j = col; j < col + qtdecol; j++){
			if(A[i][j] == '1') um = true;
			else zero = true; 
		}
	}
	if(charsonline >= 50){
		printf("\n");
		charsonline = 0;
	}
	charsonline++;
	if(um){
		if(zero){
			printf("D");
			BtoD(linha, (qtdelinha+1)/2, col, (qtdecol+1)/2);
			BtoD(linha, (qtdelinha+1)/2, col + (qtdecol+1)/2, qtdecol/2);
			BtoD(linha + (qtdelinha+1)/2, qtdelinha/2, col, (qtdecol+1)/2);
			BtoD(linha + (qtdelinha+1)/2, qtdelinha/2, col + (qtdecol+1)/2, qtdecol/2);
			return;
		}
		printf("1");
		return;
	}
	if(zero)
		printf("0");
}

void DtoB(int linha, int qtdelinha, int col, int qtdecol){
	if(qtdelinha <= 0 || qtdecol <= 0) return;
	scanf(" %c", &type);
	if(type == 'D'){
		DtoB(linha, (qtdelinha+1)/2, col, (qtdecol+1)/2);
		DtoB(linha, (qtdelinha+1)/2, col + (qtdecol+1)/2, qtdecol/2);
		DtoB(linha + (qtdelinha+1)/2, qtdelinha/2, col, (qtdecol+1)/2);
		DtoB(linha + (qtdelinha+1)/2, qtdelinha/2, col + (qtdecol+1)/2, qtdecol/2);
		return;
	}
	if(type == '0'){
		for(int i = linha; i < linha + qtdelinha; i++)
			for(int j = col; j < col + qtdecol; j++)
				A[i][j] = '0';
		return;
	}
	if(type == '1'){
		for(int i = linha; i < linha + qtdelinha; i++)
			for(int j = col; j < col + qtdecol; j++)
				A[i][j] = '1';
		return;
	}
}

int main(){
	while(true){
		if(type == '0')
			scanf(" %c", &type);
		if(type == '#') break;
		scanf("%d%d", &linhas, &colunas);
		charsonline = 0;
		if(type == 'B'){
			for(int i = 0; i < linhas; i++)
				for(int j = 0; j < colunas; j++)
					scanf(" %c", &A[i][j]);
			printf("D%4d%4d\n", linhas, colunas);
			BtoD(0, linhas, 0, colunas);
			printf("\n");
			scanf(" %c", &type);
		}
		else{
			DtoB(0, linhas, 0 , colunas);
			printf("B%4d%4d\n", linhas, colunas);
			for(int i = 0; i < linhas; i++)
				for(int j = 0; j < colunas; j++){
					if(charsonline >= 50){
						printf("\n");
						charsonline = 0;
					}
					charsonline++;
					printf("%c", A[i][j]);
				}
			printf("\n");
			scanf(" %c", &type);
		}
	}
}