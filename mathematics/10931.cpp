#include <cstdio>

int main()
{
	int n;
	while(scanf("%d", &n) , n)
	{
		int sum = 0;
		int high = -1;
		for(int i = 0; i < 31; i++)
		{
			if(n & (1 << i)){
				high = i;
				sum++;
			}
		}

		printf("The parity of ");
		for(int i = high; i >= 0; i--)
		{
			if(n & (1 << i))
				printf("1");
			else
				printf("0");
		}
		printf(" is %d (mod 2).\n", sum);
	}
}