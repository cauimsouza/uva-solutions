#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int casos_teste, // numero de casos de teste
		sold_verdes, // numero de soldados verdes
		sold_azuis, // numero de soldados azuis
		campos, // numero de campos de batalha
		k = 1; // numero do caso de teste atual
	int *venc; // arrays com as forças finais dos vencedores de cada campo de batalha
			   // se > 0, vende venceu, se < 0, azul venceu  
	multiset<int> verdes, // conjunto do exercito verde
				  azuis; // conjunto do exercito azul
	multiset<int>::iterator it; // para percorrer o exercito em ordem descendente

	scanf("%d", &casos_teste);
	while(casos_teste--){
		if(k++ > 1)
			printf("\n");
		verdes.clear();
		azuis.clear();
		scanf("%d%d%d", &campos, &sold_verdes, &sold_azuis);
		venc = new int[campos+10];

		// lendo os exércitos
		int x; // força do soldado
		while(sold_verdes--){
			scanf("%d", &x);
			verdes.insert(x);
		}
		while(sold_azuis--){
			scanf("%d", &x);
			azuis.insert(x);
		}
		
		// e a batalha começa!
		while(!verdes.empty() && !azuis.empty()){
			int i;
			for (i = 0; i < campos; ++i)
			{
				if(!verdes.empty() && !azuis.empty()){
					it = verdes.end();
					it--;
					venc[i] = *it;
					verdes.erase(it);

					it = azuis.end();
					it--;
					venc[i] -= *it;
					azuis.erase(it);
				}
				else
					break;
			}
			for (int j = 0; j < i; ++j)
			{
				if(venc[j] > 0)
					verdes.insert(venc[j]);
				else if(venc[j] < 0)
					azuis.insert(-venc[j]);
			}
		}

		if(!verdes.empty()){
			printf("green wins\n");
			it = verdes.end();
			while(it != verdes.begin()){
				it--;
				printf("%d\n", *it);
			}
		}
		else if(!azuis.empty()){
			printf("blue wins\n");
			it = azuis.end();
			while(it != azuis.begin()){
				it--;
				printf("%d\n", *it);
			}
		}
		else
			printf("green and blue died\n");

		delete[]venc;
	}


	return 0;
}
