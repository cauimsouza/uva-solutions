#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()

int main(){
	int casos, k = 1;
	char linha[110];
	scanf("%d", &casos);
	while(casos--){
		int n;
		scanf("%d %s", &n, linha);
		int cont = 0, i = 0, lim = -1;
		for(i = 0; i < n; i++){
			if(linha[i] == '.' && lim < i){
				cont++;
				lim = i + 2;
			}
		}
		
		printf("Case %d: %d\n", k++, cont);
	}
}
