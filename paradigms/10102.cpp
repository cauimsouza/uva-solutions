#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000

int main()
{
	int n;
	while(scanf("%d", &n) != EOF){
		char **A = new char*[n+10];
		for (int i = 0; i < n+10; ++i)
			A[i] = new char[n+10];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) 
				scanf(" %c", &A[i][j]);
		
		int maxMin = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(A[i][j] == '1'){
					int minDist = inf;
					for(int a = 0; a < n; a++){
						for(int b = 0; b < n; b++){
							if(A[a][b] == '3' && minDist > abs(a-i)+abs(b-j)) minDist = abs(a-i) + abs(b-j);
						}
					}
					if(minDist > maxMin) maxMin = minDist;
				}
			}
		}

		printf("%d\n", maxMin);			
		
		for(int i = 0; i < n + 10; i++)
			delete[]A[i];
		delete[]A;
	}

	return 0;
}