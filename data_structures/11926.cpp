#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()
#define MILHAO 1000000
bitset<MILHAO+10> end; // livre para ter o fim de uma tarefa se 0
bitset<MILHAO+10> beg;	// livre para ter o inicio de uma tarefa se 0

int main(int argc, char const *argv[])
{
	
	int unica, repet, inicio, fim, periodo;
	bool conflito;
	while(scanf("%d%d", &unica, &repet), unica || repet){
		end.reset();
		beg.reset();
		conflito = false;

		while(unica--){
			scanf("%d%d", &inicio, &fim);
			if(beg.test(inicio) || end.test(fim))	conflito = true;
			if(!conflito){
				beg[inicio] = 1;
				end[fim] = 1;
				for(int i = inicio+1; i < fim; i++){
					if(beg[i] || end[i])	conflito = true;
					beg[i] = end[i] = 1;
				}
			}
		}
		while(repet--){
			scanf("%d%d%d", &inicio, &fim, &periodo);
			while(inicio < MILHAO && !conflito){
				if(beg[inicio] || end[fim])	conflito = true;
				if(!conflito){
					beg[inicio] = 1;
					end[fim] = 1;
					for(int i = inicio+1; i < fim; i++){
						if(beg[i] || end[i])	conflito = true;
						beg[i] = end[i] = 1;
					}
				}
				inicio += periodo;
				fim = min(MILHAO, fim+periodo);
			}
		}

		if(conflito)	printf("CONFLICT\n");
		else	printf("NO CONFLICT\n");
	}

	return 0;
}
