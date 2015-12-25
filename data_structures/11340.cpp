#include <bits/stdc++.h>
using namespace std;

#define REC(i,a,b) for(int i = int(a); i <= int(b); i++)

int HT[300];

int main(){
	
	int t; // casos de teste
	int k; // numero de caracteres pagos
	char c;

	scanf("%d", &t);
	while(t--){
		REC(i, 0, 290)	HT[i] = 0;
		scanf("%d", &k);
		REC(i, 1, k){
			int value; // valor do caractere
			scanf(" %c %d", &c, &value);
			HT[int(c)+128] = value;
		}

		int linhas; // quantidade de linhas	
		long long valor = 0; // valor a ser pago
		scanf("%d", &linhas);
		getchar();
		while(linhas--){
			c = getchar();
			while(c != '\n' && c != EOF){
				valor += HT[int(c)+128];
				c = getchar();
			}
		}
		printf("%lld.%02lld$\n", valor/100, valor%100);
	}

	return 0;
}
