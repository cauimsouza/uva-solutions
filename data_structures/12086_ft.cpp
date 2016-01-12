#include <bits/stdc++.h>
using namespace std;

#define LSOne(i) (i & (-i))
typedef vector<int> vi;

class FenwickTree{
	vi ft;
public:
	int rsq(int b){ // return RSQ[1...b]
		int sum = 0;for(; b; b -= LSOne(b)) sum += ft[b]; return sum; }

	int rsq(int a, int b){ // return RSQ[a...b]
		return rsq(b) - (a == 1 ? 0 : rsq(a - 1));	}

	FenwickTree(int n): ft(n + 1, 0){ }

	void adjust(int k, int v){
		for(; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

int main()
{
	int pots; // number of potiometers
	int count = 0;
	while(scanf("%d", &pots), pots){
		if(count) printf("\n");

		FenwickTree ft(pots);
		int res;
		for (int i = 1; i <= pots; ++i)
		{	
			scanf("%d", &res);
			ft.adjust(i, res);
		}


		printf("Case %d:\n", ++count);
		char c;
		int a, b;
		while(scanf(" %c", &c), c != 'E'){
			scanf("%d %d", &a, &b);
			if(c == 'S'){
				int olderKey = ft.rsq(a, a);
				ft.adjust(a, b - olderKey);
			}
			else
				printf("%d\n", ft.rsq(a, b));
		}
		scanf("ND");
	}
	return 0;
}