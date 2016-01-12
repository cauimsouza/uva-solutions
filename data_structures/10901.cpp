#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)
#define time .first
#define index .second
#define mp make_pair

int main(int argc, char const *argv[])
{
	int t, k = 0; // casos de teste

	scanf("%d", &t);
	while(t--){
		if(k++)	printf("\n");
		int limite,	// limite de carros na balsa
			tempo,	// tempo para a balsa atravessar o rio
			carros; // qtde de carros
			scanf("%d%d%d", &limite, &tempo, &carros);
		int x, // tempo de chegada do carro
			tempo_balsa,
			i;
		bool lado = true; // lado da balsa, true: esquerdo, false: direito
		string ladoi;
		queue< pair<int,int> > left, right;

		i = 0; 
		while(carros--){
			scanf("%d", &x);
			cin >> ladoi;
			if(ladoi == "left")	left.push(mp(x,i++));
			else	right.push(mp(x,i++));
		}

		int *temp = new int[i+10]; // indices dos carros vao de 0 a i-1
		tempo_balsa = 0;

		while(!left.empty() && !right.empty()){
			if(lado){ // balsa esta no lado esquerdo
				if(tempo_balsa >= left.front().first){ // balsa chegou depois do carro da esquerda
					int cont = 0;
					do{
						temp[left.front().second] = tempo_balsa + tempo;
						cont++;
						left.pop();
					}while(cont < limite && !left.empty() && left.front().first <= tempo_balsa);
					tempo_balsa += tempo;
				}
				else if(left.front().first <= right.front().first){ // balsa chegou antes do carro da esquerda, que chegou antes do carro da direita
					tempo_balsa = left.front().first;
					int cont = 0;
					do{
						temp[left.front().second] = tempo_balsa + tempo;
						cont++;
						left.pop();
					}while(cont < limite && !left.empty() && left.front().first <= tempo_balsa);
					tempo_balsa += tempo;
				}
				else{ // balsa chegou antes do carro da direita, que chegou antes do carro da esquerda
					tempo_balsa = max(right.front().first,tempo_balsa) + tempo;
				}
				lado = false;
			}
			else{
				if(tempo_balsa >= right.front().first){ // balsa chegou depois do carro da direita
					int cont = 0;
					do{
						temp[right.front().second] = tempo_balsa + tempo;
						cont++;
						right.pop();
					}while(cont < limite && !right.empty() && right.front().first <= tempo_balsa);
					tempo_balsa += tempo;
				}
				else if(right.front().first <= left.front().first){ // balsa chegou antes do carro da direita, que chegou antes do carro da esquerda
					tempo_balsa = right.front().first;
					int cont = 0;
					do{
						temp[right.front().second] = tempo_balsa + tempo;
						cont++;
						right.pop();
					}while(cont < limite && !right.empty() && right.front().first <= tempo_balsa);
					tempo_balsa += tempo;
				}
				else{ // balsa chegou antes do carro da esquerda, que chegou antes do carro da direita
					tempo_balsa = max(left.front().first,tempo_balsa) + tempo;
				}
				lado = true;
			}
		}

		while(!left.empty()){
			if(!lado){
				tempo_balsa = tempo + max(left.front().first,tempo_balsa);
				lado = true;
			}
			else{
				tempo_balsa = max(tempo_balsa, left.front().first);
				int cont = 0;
				do{
					temp[left.front().second] = tempo_balsa + tempo;
					left.pop();
					cont++;
				}while(cont < limite && !left.empty() && left.front().first <= tempo_balsa);
				tempo_balsa += tempo;
				lado = false;
			}
		}

		while(!right.empty()){
			if(lado){
				tempo_balsa = tempo + max(right.front().first, tempo_balsa);
				lado = false;
			}
			else{
				tempo_balsa = max(tempo_balsa, right.front().first);
				int cont = 0;
				do{
					temp[right.front().second] = tempo_balsa + tempo;
					right.pop();
					cont++;
				}while(cont < limite && !right.empty() && right.front().first <= tempo_balsa);
				tempo_balsa += tempo;
				lado = true;
			}
		}
		REC(j, 0, i-1)
			printf("%d\n", temp[j]);

		delete[]temp;
	}

	return 0;
}
