#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)


int main(int argc, char const *argv[])
{
	int t; // casos de teste

	scanf("%d", &t);
	while(t--){
		int n,	// numero de estacoes
			cap,	// capacidade do carrinho
			lim,	// capacidade das filas
			tempo,	// tempo total
			i;	// numero da estacao
		long long ok;

		scanf("%d%d%d", &n, &cap, &lim);

		stack<int> carrinho;
		queue<int> *filas = new queue<int>[n+10];
		for (int i = 1; i <= n; ++i)
		{
			int cont, x;
			scanf("%d", &cont);
			while(cont--){
				scanf("%d", &x);
				filas[i].push(x);
			}
		}

		tempo = -2;
		i = n;
		while(true){
			ok = 0;
			for(int j = 1; j <= n; j++)	ok += (int)filas[j].size();
			if(ok == 0 && carrinho.empty())	break;

			tempo += 2;
			i = (i == n)?1:(i+1);
	
			while(true){	// aqui eu desempilho
				if(carrinho.empty())	break;
				else{
					if(carrinho.top() == i){
						carrinho.pop();
						tempo++;
					}
					else if((int)filas[i].size() < lim){
						filas[i].push(carrinho.top());
						tempo++;
						carrinho.pop();
					}
					else	break;
				}
			}
			
			while(true){	// aqui eu empilho
				if(filas[i].empty() || (int)carrinho.size() >= cap)	break;
				tempo++;
				carrinho.push(filas[i].front());
				filas[i].pop();
			}
		}

		printf("%d\n", tempo);
		delete[]filas;
	}

	return 0;
}
