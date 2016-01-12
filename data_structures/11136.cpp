#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; // numero de dias
	multiset<int> ms;
	multiset<int>::iterator it;
	while(scanf("%d", &n), n){
		ms.clear();
		long long soma = 0;
		for (int i = 0; i < n; ++i)
		{
			int bills, bill;
			scanf("%d", &bills);
			for (int j = 0; j < bills; ++j)
			{
				scanf("%d", &bill);
				ms.insert(bill);
			}
			it = ms.begin();
			soma -= *it;
			ms.erase(it);
			it = ms.end();
			soma += *(--it);
			ms.erase(it); 
		}
		printf("%lld\n", soma);
	}
}
