#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int roun; // round
	bool palavras[30];	// letras da palavra desafio
	bool escolhidas[30]; // letras que ja foram escolhidas
	bool erradas[30]; // letras erradas
	int falha; // contador de falhas
	int letras; // numero de letras distintas da palavra desafio
	char c;
	bool ganhou = true;

	while(true){
		scanf("%d", &roun);
		if(roun == -1)	break;
		
		getchar();
		for (int i = 0; i < 30; ++i)
		{
			palavras[i] = escolhidas[i] = erradas[i] = false;
		}

		letras = 0;
		while((c = getchar()) != '\n'){
			if(!palavras[c-'a']) {
				palavras[c-'a'] = true;
				letras++;
			}
		}

		ganhou = false;
		falha = 0;
		while((c = getchar()) != '\n'){
			if(!palavras[c - 'a']){
				if(!erradas[c - 'a']){
					falha++;
					erradas[c - 'a'] = true;
				}
			}
			else if(!escolhidas[c-'a']){
				letras--;
				escolhidas[c-'a'] = true;
				if(!letras && falha < 7)	ganhou = true;
			}
		}

		printf("Round %d\n", roun);
		if(ganhou)	printf("You win.\n");
		else if(falha > 6)	printf("You lose.\n");
		else	printf("You chickened out.\n");
	}


	return 0;
}
