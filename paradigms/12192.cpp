#include <bits/stdc++.h>
using namespace std;

int main(){
	int rows, colums;
	while(scanf("%d%d", &rows, &colums), rows){
		int **area = new int*[rows];
		for(int i = 0; i < rows; i++)
			area[i] = new int[colums];

		for(int i = 0; i < rows; i++)
			for(int j = 0; j < colums; j++){
				scanf("%d", &area[i][j]);
			}

		int queries;
		scanf("%d", &queries);
		int *idxinicio = new int[rows+10], *idxfim = new int[rows+10];
		while(queries--){
			int L, H;
			scanf("%d%d", &L, &H);
			int maior = 0;

			for(int i = 0; i < rows; i++){
				idxinicio[i] = lower_bound(&area[i][0],&area[i][colums], L) - area[i];
				idxfim[i] = upper_bound(&area[i][0],&area[i][colums], H) - area[i];
			}
			for(int i = 0; i < rows - maior; i++){
				for(int j = i + maior; j < rows; j++){
					int dif = min(j - i + 1, idxfim[j] - idxinicio[i]);
					if(dif > maior) maior = dif;
					else continue;
				}
			}

			printf("%d\n", maior);
		}
		printf("-\n");

		for(int i = 0; i < rows; i++)
			delete[]area[i];
		delete[]idxfim;
		delete[]idxinicio;
	}
}
