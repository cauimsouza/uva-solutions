#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()

int main(){
	int valor[1010];
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &valor[i]);

		int resp = 2, soma = 1;
		for(int i = 1; i < n - 1; i++){
			if(soma + valor[i] < valor[i+1]){
				soma += valor[i];
				resp++;
			}
		}
		printf("%d\n", resp);
	}
}
