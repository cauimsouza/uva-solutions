#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)
#define pb push_back
#define mp	make_pair
#define sz(v) int((v).size())

int ciclos[10000];
int n;

bool aberto(int farol, int tempo){
	if((tempo/ciclos[farol])%2 == 0){
		if(tempo%ciclos[farol] + 5 < ciclos[farol])	return true;
	}
	return false;
}

int main(){
	
	int x;
	int tempo, menor;
	int i, j;
	
	while(true){
		scanf("%d", &x);
		if(x == 0)	break;

		n = 0;
		ciclos[n++] = x;
		menor = x;
		while(scanf("%d", &x), x){
			ciclos[n++] = x;
			if(x < menor)	menor = x;
		}

		bool ok = false;
		tempo = 2*menor;
		while(!ok && tempo < 20000){
			ok = false;
			for (j = 0; j < menor - 5 && !ok; ++j)
			{
				ok = true;
				for (i = 0; i < n && ok; ++i)
				{
					if(!aberto(i, tempo+j))	ok = false;
				}
				if(ok)	tempo += j;
			}
			if(ok)	break;
			tempo += 2*menor;
		}
		if(ok && tempo <= 18000)	printf("%02d:%02d:%02d\n", tempo/3600,(tempo%3600)/60, (tempo%3600)%60);
		else	printf("Signals fail to synchronise in 5 hours\n");
	}
	

	return 0;
}
