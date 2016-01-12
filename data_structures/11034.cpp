#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)

int main(int argc, char const *argv[])
{
	int t; // casos de teste
	

	scanf("%d", &t);
	while(t--){
		int comp, // comprimento da balsa
			ncar; // numero de carros a atravessar
			scanf("%d%d", &comp, &ncar);
			comp *= 100; // metros -> centimetros
		queue<int> esq, dir; // sequencia das alturas dos carros que chegaram em cada banco

		while(ncar--){
			int tam;
			char lado[10];
			scanf("%d %s", &tam, lado);
			if(strcmp(lado, "left")) dir.push(tam);
			else	esq.push(tam);
		}

		int cont = 0; // numero de travessias
		bool lado = true; // lado da barca: true->esquerda, false->direita
		while(!esq.empty() || !dir.empty()){
			cont++;
			int soma = 0;
			if(lado){
				while(!esq.empty() && soma + esq.front() <= comp){
					soma += esq.front();
					esq.pop();
				}
				lado = false;
			}
			else{
				while(!dir.empty() && soma + dir.front() <= comp){
					soma += dir.front();
					dir.pop();
				}
				lado = true;
			}
		}
		printf("%d\n", cont);
	}

	return 0;
}
