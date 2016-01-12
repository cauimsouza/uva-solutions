#include <bits/stdc++.h>
using namespace std;

#define REC(i,a,b) for(int i = int(a); i <= int(b); i++)
#define LIM 1000

char partida[LIM];
char chegada[LIM];
int n;

void Recursiva(vector<char>& V, stack<char>& P, int pops, int pushs, int ipartida, int ichegada, bool op){
	if(op){
		if(pushs++ >= n)	return;
		P.push(partida[ipartida++]);
		V.push_back('i');
	}
	else{
		if(pops >= n || pops >= pushs || P.empty() || chegada[ichegada++] != P.top())	return;
		P.pop();
		pops++;
		V.push_back('o');
	}
 
	if((int)V.size() == 2*n){
		printf("%c", V[0]);
		for(int i = 1; i < (int)V.size(); i++) printf(" %c", V[i]);
		printf("\n");
	}

	Recursiva(V, P, pops, pushs, ipartida, ichegada, true);
	Recursiva(V, P, pops, pushs, ipartida, ichegada, false);
	V.pop_back();
	if(op)	P.pop();
	else	P.push(chegada[ichegada-1]);
}

int main(){
	
	while(fgets(partida, LIM, stdin)){
		fgets(chegada, LIM, stdin);

		printf("[\n");
		if(strlen(partida) == strlen(chegada)){
			n = strlen(partida) - 1;
			vector<char> V;
			stack<char> P;
			Recursiva(V, P, 0, 0, 0, 0, true);
		}
		printf("]\n");
	}

	return 0;
}
