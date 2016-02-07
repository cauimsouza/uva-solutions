#include <bits/stdc++.h>
using namespace std;

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		int n;
		scanf("%d", &n);
		int *array = new int[n+10];
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &array[i]);
			int temp = array[i];
			for(int j = 0; j < i; j++)
				if(array[j] <= temp) sum++;
		}
		printf("%d\n", sum);

		delete[]array;
	}

	return 0;
}