#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		int A, B, C;
		scanf("%d%d%d", &A, &B, &C);

		bool noSolution = true;
		if(C >= 0){
			for(int x = (int) ceil(-sqrt(C)); noSolution && x <= (int) floor(sqrt(C)); x++){
				for(int y = x + 1; noSolution && y <= (int) floor(sqrt(C)); y++){
					int z = A - x - y;
					if(z != x && z != y && x*y*z == B && (x*x)+(y*y)+(z*z) == C){
						printf("%d %d %d\n", x, y, z);
						noSolution = false;
					}
				}
			}
		}
		if(noSolution)
			printf("No solution.\n");
		
	}	

	return 0;
}
