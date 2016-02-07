#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
typedef vector<int> vi;

int main(){
	int n, k = 0;
	int size[10010];
	while(scanf("%d", &n), n){
		if(k++) printf("\n");
		rep(i, 0, n) scanf("%d", &size[i]);
		sort(size, size + n);
		int maior = 1, tam = 1;
		for(int j = 1; j < n; j++){
			if(size[j] == size[j-1]){
				tam++;
				if(tam > maior) maior = tam;
			}			
			else{
				tam = 1;	
			}
		}
		printf("%d\n", maior);

		vector<int> cnjt[maior];
		for(int i = 0; i < n; i++){
			cnjt[i%maior].push_back(size[i]);
		}

		for(int i = 0; i < maior; i++){
			printf("%d", cnjt[i][0]);
			for(int j = 1; j < sz(cnjt[i]); j++)
				printf(" %d", cnjt[i][j]);
			printf("\n");
		}
	}

}
