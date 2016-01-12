#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef pair<int , pair<int, pair<int, pair<int, int> > > > tupla;

int main(int argc, char const *argv[])
{
	int frosh; // numero de calouros
	int vetor[5]; // armaezena os cursos escolhidos em ordem crescente
	int maior, cont;
	map<tupla, int> mapa;
	map<tupla, int>::iterator it;

	while(scanf("%d", &frosh), frosh){
		mapa.clear();
		maior = 0;
		while(frosh--){
			for (int i = 0; i < 5; ++i)
			{
				scanf("%d", &vetor[i]);
			}
			sort(vetor,vetor+5);

			tupla aux = mp(vetor[0], mp(vetor[1], mp(vetor[2], mp(vetor[3], vetor[4]))));

			it = mapa.find(aux);
			if(it == mapa.end()){
				mapa[aux] = 1;
				if(!maior){
					cont = 1;
					maior = 1;
				}
				else if(maior == 1)
					cont++;
			}
			else{
				mapa[aux]++;
				if(mapa[aux] > maior){
					cont = 1;
					maior = mapa[aux];
				}
				else if(mapa[aux] == maior)
					cont++;
			}
		}		

		printf("%d\n", cont*maior); 
	}

	return 0;
}
