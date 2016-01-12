#include <stdio.h>
#include <stdlib.h>

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		int barLength, numBars;
		int *length;
		scanf("%d%d", &barLength, &numBars);
		length = new int[numBars+10];

		for(int p = 0; p < numBars; p++)
			scanf("%d", &length[p]);

		bool success = false;
		for (int i = 1; !success && i < (1 << numBars); ++i)
		{	
			int sum = 0;
			for(int j = 0; j < numBars; j++){
				if(i & (1 << j)) sum += length[j];
				if(sum == barLength){ success = true; break; }
				if(sum > barLength) break;
			}
		}

		if(success)
			printf("YES\n");
		else
			printf("NO\n");

		delete[]length;
	}

	return 0;
}
