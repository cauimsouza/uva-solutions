#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t, // casos de teste
		cont, // numero de arvores no caso de teste
		k = 0; // verifica se estamos no 2 caso de teste ou posterior
	map<string , int> lista; //mapa que mapeia cada nome de árvore para o número de vezes que a árvore aparece
	string arvore; // nome da arvore
	map<string, int>::iterator it;

	scanf("%d\n\n", &t);
	while(t--){
		if(k++)	printf("\n");
		lista.clear();
		cont = 0;
		getline(cin, arvore); // lê a primeira árvore
		do{
			it = lista.find(arvore);
			if(it == lista.end()) // primeira vez que essa árvore aparece no caso de teste
				lista[arvore] = 1;
			else
				lista[arvore]++;
			cont++;
			getline(cin, arvore);
		}while(arvore.length() > 0);

		for(it = lista.begin(); it != lista.end(); it++)
			printf("%s %.4f\n", ((string)it->first).c_str(), 100.0*(it->second)/(1.0*cont));
	}
	return 0;
}
