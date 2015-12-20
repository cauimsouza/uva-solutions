#include <bits/stdc++.h>
using namespace std;

#define rec(i, a, b)	for(int i = (a); i <= (b); i++)

int main(int argc, char const *argv[])
{
	int diagonalp, diagonals;
	int p_linhas[10], p_colunas[10];
	int games, x, rodada, numeros;
	bool bingo; // ja deu deu bingo?
	map<int, pair<int,int> > cartao; // numero x, na linha i e coluna j
	scanf("%d", &games);

	while(games--){
		cartao.clear();
		bingo = false;
		rec(i, 1, 5){ // limpa o numero de numeros ja sorteados em cada linha e coluna
			if(i == 3)	p_linhas[i] = p_colunas[i] = 4;
			else	p_linhas[i] = p_colunas[i] = 5;
		}	
		diagonals = diagonalp = 4;

		rec(i, 1, 5){
			rec(j, 1, 5){
				if(i == 3 && j == 3)	continue;
				scanf("%d", &x);
				cartao[x] = make_pair(i,j);
			}
		}

		rodada = 1;
		while(!bingo){
			scanf("%d", &x);
			if(cartao.find(x) != cartao.end()){
				int linha, coluna;
				linha = cartao[x].first;
				coluna = cartao[x].second;
				p_linhas[linha]--;
				p_colunas[coluna]--;
				if(linha == coluna)	diagonalp--;
				if(linha + coluna == 6)	diagonals--;
				if(!p_linhas[linha] || !p_colunas[coluna] || !diagonals || !diagonalp){
					bingo = true;
					numeros = rodada;
				}
			}
			rodada++;
		}
		while(rodada++ <= 75)	scanf("%*s");

		printf("BINGO after %d numbers announced\n", numeros);
	}
	return 0;
}
