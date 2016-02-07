#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> possibleScores;
	for(int i = 0; i <= 20; i++){
		possibleScores.insert(i);
		possibleScores.insert(2*i);
		possibleScores.insert(3*i);
	}
	possibleScores.insert(50);
	vector<int> nums(possibleScores.begin(), possibleScores.end());
	int N = (int) nums.size();

	int n;
	while(scanf("%d", &n), n > 0){
		int comb = 0, perm = 0;

		for(int i = 0; i < N; i++){
			int x = nums[i];
			int sum = n;
			if(x <= sum) sum -= x;

			for(int j = i; j < N; j++){
				int y = nums[j];
				bool add = false;
				if(y <= sum){
					add = true;
					sum -= y;
				}

				for(int k = j; k < N; k++){
					int z = nums[k];
					sum -= z;
					if(sum == 0){
						comb++;
						if(x != y && y != z) perm += 6;
						else if((x == y && y != z) || (x != y && y == z) ) perm += 3;
						else perm ++;
					}
					sum += z;
				}
				if(add) sum += y;
			}
		}

		 if(comb){
		 	printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
		 	printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
		 }
		 else
		 	printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n); 
		 printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");

	return 0;
}