#include <bits/stdc++.h>
using namespace std;

#define sz(v) int((v).size())
#define tr(v, i) for(typeof((v).begin()) i = (v).begin() ; i != (v).end(); i++)

int maior; // maior numero de peças que foi possivel por sobre o tabuleiro
int linhas, colunas;
bool ja_deu;
vector< pair<int,int> > tab; // (linha, coluna)

void _queen(int i);

int main(int argc, char const *argv[])
{
	int t; // casos de teste
	char peca;

	scanf("%d", &t);
	while(t--){
		scanf(" %c%d%d", &peca, &linhas, &colunas);
		if(linhas > colunas)	swap(linhas, colunas);
		tab.clear();
		maior = 0;

		if(peca == 'r'){
			maior = min(linhas, colunas);
		}
		else if(peca == 'Q'){
			ja_deu = false;
			_queen(1);
		}
		else if(peca == 'K'){
			maior = ((colunas+1)/2) * ((linhas+1)/2);
		}
		else{
			maior = ((colunas+1)/2)* ((linhas+1)/2) + (colunas/2)*(linhas/2);
		}
		
		printf("%d\n", maior);
	}

	return 0;
}

// conta o maior numero possivel de rainhas que se pode por sobre o tabuleiro
void _queen(int i){
	if(ja_deu)	return;
	if(i > linhas || i > colunas){
		ja_deu = true;
		return;
	}

	bool deu_certo;
	for(int j = 1; j <= colunas && !ja_deu; j++){
		deu_certo = true;
		tr(tab, k){
			if(abs(j - k->second) == abs(i - k->first)){
				deu_certo = false;
				break;
			}
		}
		if(deu_certo){
			if(i > maior)	maior = i;
			tab.push_back(make_pair(i,j));
			_queen(i+1);
			tab.pop_back();
		}
		
	}
}
