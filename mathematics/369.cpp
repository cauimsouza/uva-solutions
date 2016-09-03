#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
	using namespace std;
	vector<int> num, den;
	int highest = -1;
	int a, b;
	while(scanf("%d %d", &a, &b), (a || b))
	{
		num.push_back(a);
		den.push_back(b);
		highest = max(highest, a);
	}

	long long **triangle = new long long *[highest + 5];
	for(int i = 0; i < highest + 5; i++)
		triangle[i] = new long long[highest + 5];

	for(int i = 0; i <= highest; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			if(j == 0 || j == i) triangle[i][j] = 1;
			else triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
		}
	}

	for(int i = 0; i < (int) num.size(); i++)
	{
		printf("%d things taken %d at a time is %lld exactly.\n", num[i], den[i], triangle[num[i]][den[i] ]);
	}
	return 0;
}