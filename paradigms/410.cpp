#include <bits/stdc++.h>
using namespace std;

int main(){
	int chambers, specimens, cont = 1;
	int massas[15];
	while(scanf("%d%d", &chambers, &specimens) != EOF){
		memset(massas, 0, sizeof massas);
		double media = 0;
		for(int i = 0; i < specimens; i++){
			scanf("%d", &massas[i]);
			media += massas[i];
		}
		media /= chambers;

		sort(massas, massas + 2 * chambers);

		printf("Set #%d\n", cont++);
		double imbalance = 0;
		for(int i = 0; i < chambers; i++){
			printf(" %d:", i);
			if(massas[i]) printf(" %d", massas[i]);
			double sum = massas[i];
			if(massas[2 * chambers - i - 1])printf(" %d", massas[2 * chambers - i - 1]);
			sum += massas[2*chambers - i - 1];
			imbalance += fabs(sum - media);
			printf("\n");
		}
		printf("IMBALANCE = %.5f\n\n", imbalance);
	}
}