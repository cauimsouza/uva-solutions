#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test_cases;
	scanf("%d", &test_cases);
	while(test_cases--){
		int degree, *coef;
		scanf("%d", &degree);
		coef = new int[degree+10];
		for (int i = 0; i <= degree; ++i){
			scanf("%d", &coef[i]);}

		int d, k, n;
		scanf("%d %d", &d, &k);
		n = (int) floor((-1 + sqrt((8.0*k)/d))/2) + 1;
		long long sum = 0;
		for(int i = degree; i >= 0; i--){
			sum *= n;
			sum += coef[i];	}
		printf("%lld\n", sum);

		delete[]coef;
	}

	return 0;
}