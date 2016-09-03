#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int n;
	while(scanf("%d", &n), n){
		int raiz;
		for(raiz = 1; raiz * raiz <= n; raiz++);
		raiz--;
		int quad = raiz * raiz;
		if(quad == n){
			if(raiz % 2)
				printf("%d %d\n", 1, raiz);
			else
				printf("%d %d\n", raiz, 1);
		}
		else if(raiz % 2){

			if(n - quad <= raiz + 1){
				printf("%d %d\n", n - quad, raiz + 1);
			}
			else{
				printf("%d %d\n", raiz + 1, (raiz + 1) * (raiz + 1) - n + 1);
			}
		}
		else{
			if(n - quad <= raiz){
				printf("%d %d\n", raiz + 1, n - quad);
			}
			else{
				printf("%d %d\n", (raiz + 1) * (raiz + 1) - n + 1, raiz + 1);
			}
		}
	}
}