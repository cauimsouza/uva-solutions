#include <bits/stdc++.h>
using namespace std;

#define STR_LEN 20000
#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)

char LC(char a){
	if(a <= 'z')	return a;
	else	return a - 'A' + 'a';
}

int main(int argc, char const *argv[])
{
	int t, i, j, ordem, k, cont = 1;
	char entrada[STR_LEN], c;
	bool magica;
	scanf("%d", &t);
	getchar();

	while(t--){
		i = 0;
		while((c = getchar()) != '\n'){
			if(isalpha(c))
				entrada[i++] = LC(c);
		}
		
		ordem = int(sqrt(0.5 + i));
		if(ordem*ordem != i){
			printf("Case #%d:\nNo magic :(\n", cont++);
			continue;
		}

		char **A = new char*[ordem+10];
		REC(j, 1, ordem)
			A[j] = new char[ordem+10];

		k = 1;
		REC(j, 1, ordem){
			REC(t, 1, ordem){
				A[j][t] = entrada[k++ - 1];
			}
		}

		magica = true;
		for(i = 1; i <= (ordem+1)/2 && magica; i++){
			for(j = 1; j <= ordem && magica; j++){
				if((A[i][j] != A[ordem-i+1][ordem-j+1]) || (A[j][i] != A[ordem-j+1][ordem-i+1]) || (A[i][j] != A[j][i]))	magica = false;
			}
		}
		if(!magica)
			printf("Case #%d:\nNo magic :(\n", cont++);
		else
			printf("Case #%d:\n%d\n", cont++, ordem);

		REC(i, 1, ordem)
			delete[]A[i];
		delete[]A;
	}

	return 0;
}

