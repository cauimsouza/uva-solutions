#include <bits/stdc++.h>
using namespace std;

#define REC(i,a,b) for(int i = int(a); i <= int(b); i++)

int main(){
	
	int soldados,	// numero de soldados
		perdas; // numero de perdas
	int sold_esq, sold_dir; // soldado abatido mais a esquerda, mais a direita, respec.
	while(scanf("%d%d", &soldados, &perdas), soldados || perdas){
		int *direito = new int[soldados+10]; // direito[i] contem o parceiro direito do soldado im 0 caso nao exista
		int *esquerdo = new int[soldados+10]; // esquerdo[i] contem o parceiro esquerdo do soldado i, 0 caso nao exista
		REC(i, 1, soldados){
			direito[i] = i+1;
			esquerdo[i] = i-1;
		}
		direito[soldados] = esquerdo[1] = 0;

		REC(i, 1, perdas){
			scanf("%d%d", &sold_esq, &sold_dir);
			direito[esquerdo[sold_esq]] = direito[sold_dir];
			esquerdo[direito[sold_dir]] = esquerdo[sold_esq];
			if(esquerdo[sold_esq])	printf("%d ", esquerdo[sold_esq]);
			else	printf("* ");
			if(direito[sold_dir])	printf("%d\n", direito[sold_dir]);
			else	printf("*\n");
		}
		printf("-\n");

		delete[]direito;
		delete[]esquerdo;
	}

	return 0;
}
