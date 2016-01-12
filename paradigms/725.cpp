#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main()
{
	int n, cont = 0;
	while(scanf("%d", &n), n){
		if(cont++) printf("\n");

		bool noSolution = true;
		for(int fghij = 1234; fghij <= 98765/n; fghij++){
			int abcde = fghij * n;
			int temp, used = (fghij < 10000);
			temp = abcde; while(temp){ used |= 1 << (temp % 10); temp /= 10;}
			temp = fghij; while(temp){ used |= 1 << (temp % 10); temp /= 10;}
			if(used == (1 << 10) - 1){
				printf("%05d / %05d = %d\n", abcde, fghij, n);
				noSolution = false;
			}
		}
		if(noSolution)
			printf("There are no solutions for %d.\n", n);
	}

	return 0;
}
