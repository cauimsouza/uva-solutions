#include <bits/stdc++.h>
using namespace std;

bool Reversos(char c, char b);

int main(int argc, char const *argv[])
{
	char entrada[1000];
	int i, j, tam;
	bool palindromo;

	while(true){
		fgets(entrada,1000,stdin);
		tam = strlen(entrada) - 1;
		entrada[tam] = '\0';
		
		if(strcmp(entrada, "DONE") == 0)	break;
		i = 0;
		j = tam - 1;
		palindromo = true;
		while(i < j && palindromo){
			if(isalpha(entrada[i]) && isalpha(entrada[j])){
				if((entrada[i] - 'a' == entrada[j] - 'a')|| (entrada[i] - 'a' == entrada[j] - 'A')||(entrada[i] - 'A' == entrada[j] - 'a'));
				else	palindromo = false;
				i++;
				j--;
			}
			else if(isalpha(entrada[i]))	j--;
			else if(isalpha(entrada[j]))	i++;
			else{
				i++;
				j--;
			}
		}

		if(palindromo)	printf("You won't be eaten!\n");
		else	printf("Uh oh..\n");
	}

	return 0;
}

