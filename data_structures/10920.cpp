#include <bits/stdc++.h>
using namespace std;

#define REC(i,a,b) for(int i = int(a); i <= int(b); i++)

int main(){
	
	int n,	// tamanho da espiral
		p;	// posicao da celula na espiral
	int x, y; // coordenadas cartesianas da celula
	int X, Y; // posicao do centro da espiral

	while(scanf("%d%d", &n, &p), n || p){
		X = Y = (n+1)/2;
		int q = (int)sqrt(p);
		if(q%2 && q*q == p){
			x = y = X + (q-1)/2;
		}
		else{
			if(q%2)	q += 2;
			else q++;
			x = y = X + (q-1)/2;
			p = q*q - p;
			if(p <= q-1)	y -= p;
			else{
				y -= q-1;
				p -= q-1;
				if(p <= q-1)	x -= p;
				else{
					x -= q-1;
					p -= q-1;
					if(p <= q-1)	y += p;
					else{
						y += q-1;
						p -= q-1;
						x += p;
					}
				}
			}
		}

		printf("Line = %d, column = %d.\n", y, x);
	}

	return 0;
}
