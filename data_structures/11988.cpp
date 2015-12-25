#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

int main(int argc, char const *argv[])
{
	
	list<char> lista, aux;
	char c;
	int onde_add; // 0: à esquerda, 1: à direita
	while((c = getchar()) != EOF){
		lista.clear();
		aux.clear();
		onde_add = 1;
		while(c != '\n'){
			if(c == '[' || c == ']'){// home
				if(!aux.empty()){
					if(onde_add)
						lista.splice(lista.end(), aux);
					else
						lista.splice(lista.begin(), aux);
				}
				if(c == ']')
					onde_add = 1;
				else
					onde_add = 0;
				aux.clear();
			}
			else
				aux.push_back(c);
			c = getchar();

		}
		if(!aux.empty()){
			if(onde_add)
				lista.splice(lista.end(), aux);
			else
				lista.splice(lista.begin(), aux);
		}
		for(list<char>::iterator i = lista.begin(); i != lista.end(); i++)
			putchar(*i);
		printf("\n");
	}

	return 0;
}
