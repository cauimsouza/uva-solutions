#include <bits/stdc++.h>
using namespace std;

#define inf (int)1e9

// it maps city areas numbered from 1 to 24 into x,y-coordinates  
int numToCoord(int num){
	return (num/5)*10 + num%5;
}

int main(){

	int city[5][5];
	int test_cases;
	scanf("%d", &test_cases);

	while(test_cases--){
		for(int i = 0; i < 5; i++) memset(city[i], 0, sizeof city[i]);

		int nonNull; // number of areas with people living in it
		scanf("%d", &nonNull);
		for(int i = 0; i < nonNull; i++){
			int row, column, pop;
			scanf("%d%d%d", &row, &column, &pop);
			city[row][column] = pop;
		}

		int minSum = inf;
		int bestChoice[5];
		for(int a = 0; a < 21; a++)
			for(int b = a + 1; b < 22; b++)
				for(int c = b + 1; c < 23; c++)
					for(int d = c + 1; d < 24; d++)
						for(int e = d + 1; e < 25; e++){ // OMG 5 loops !!!
							int offices[] = {a, b, c, d, e};
							int totalSum = 0;
							for(int i = 0; i < 5; i++)
								for(int j = 0; j < 5; j++)
									if(city[i][j]){
										int coords = numToCoord(a);
										int xcord = coords%10, ycord = coords/10;
										int distance = city[i][j] * (abs(xcord - j) + abs(ycord - i));
										for(int k = 1; k < 5; k++){
											coords = numToCoord(offices[k]);
											int xcord = coords%10, ycord = coords/10;
											int temp = city[i][j] * (abs(xcord - j) + abs(ycord - i));
											if(temp < distance)
												distance = temp;
										}
										totalSum += distance;
									}
							if(totalSum < minSum){
								minSum = totalSum;
								for(int i = 0; i < 5; i++)
									bestChoice[i] = offices[i];
							}								
						}

		printf("%d", bestChoice[0]);
		for(int i = 1; i < 5; i++)
			printf(" %d", bestChoice[i]);
		printf("\n");
	}

	return 0;
}
