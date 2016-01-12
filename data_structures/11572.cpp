#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	map<int, int> mapa; // par (tamanho, ocorrencia)
	map<int, int>::iterator it;
	int maior, i, t, n, // maior pacote possivel, contador da ocorrencia, numero de casos de teste, numero de snowflakes
		inicio; // ocorrencia do primeiro snowflake a entrar no pacote

	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mapa.clear();

		int x;
		maior = inicio = 0;
		for(i = 0; i < n; i++){
			scanf("%d", &x);
			it = mapa.find(x);

			//caso um snowflake de tamanho x já está no pacote
			if(it != mapa.end() && mapa[x] >= inicio)
				inicio = mapa[x]+1;

			mapa[x] = i;
			if(i - inicio + 1 > maior)
				maior = i - inicio + 1;
		}

		printf("%d\n", maior);
	} 

	return 0;
}
