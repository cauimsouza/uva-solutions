#include <bits/stdc++.h>
using namespace std;

typedef char name[30];

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		int makers;
		scanf("%d", &makers);

		name * maker = new name[makers+10];
		int *lowest = new int[makers+10];
		int *highest = new int[makers+10];
		for (int i = 0; i < makers; ++i)
		{
			scanf("%s %d %d", maker[i], &lowest[i], &highest[i]); }

		int queries;
		scanf("%d", &queries);
		while(queries--){
			int price, idx = -1;
			scanf("%d", &price);
			for(int i = 0; i < makers; i++){
				if(lowest[i] <= price && highest[i] >= price){
					if(idx >= 0){ idx = -1; break; }
					idx = i; } }
			if(idx >= 0) printf("%s\n", maker[idx]);
			else printf("UNDETERMINED\n");
		}

		delete[]maker; 
		delete[]lowest;
		delete[]highest;

		if(test_cases) printf("\n");
	}

	return 0;
}