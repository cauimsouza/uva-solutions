#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;


int main(){
	int n;
	while(scanf("%d", &n), n){
		vector<int> vet(n);
		for(int i = 0; i < n; i++){
			scanf("%d", &vet[i]);
		}
		sort(vet.begin(), vet.end());

		bool sucesso = vet[0] <= 200;
		for(int i = 1; i < n; i++){
			if(vet[i] - vet[i - 1] > 200){
				sucesso = false;
				break;
			}
		}
		sucesso = sucesso && (1422 - vet[n - 1]) * 2 <= 200;

		if(sucesso)
			printf("POSSIBLE\n");
		else
			printf("IMPOSSIBLE\n");
	}
}