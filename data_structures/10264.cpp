#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

int peso[(1 << 15)];
int pot[(1 << 15)];

int main(int argc, char const *argv[])
{
	
	int dim;
	int maior;

	while(scanf("%d", &dim) != EOF){
		for(int i = 0; i < (1 << dim); i++)	pot[i] = 0;

		for (int i = 0; i < (1 << dim); ++i)
		{
			scanf("%d", &peso[i]);
			for(int j = 0; j < dim; j++)
				pot[i ^ (1 << j)] += peso[i];
		}

		maior = 0;
		for (int i = 0; i < (1 << dim); ++i)
		{
			for (int j = 0; j < dim; ++j)
			{
				if(pot[i] + pot[i ^ (1 << j)] > maior)
					maior = pot[i] + pot[i ^ (1 << j)];
			}
		}

		printf("%d\n", maior);
	}

	return 0;
}
