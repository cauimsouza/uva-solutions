#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

int main(int argc, char const *argv[])
{
	
	
	int n, i, x, cont;
	bool ok;
	while(scanf("%d", &n), n){
		scanf("%d", &x);
		while(x){
			stack<int> estacao;
			i = 1;
			cont = 2;
			ok = true;

			while(i <= x){
				estacao.push(i);
				i++;
			}
			if(estacao.top() != x)	ok = false;
			else if(ok)	 estacao.pop();
			while(cont++ <= n){
				scanf("%d", &x);
				while(i <= x){
					estacao.push(i);
					i++;
				}
				if(estacao.top() != x)	ok = false;
				else if(ok) estacao.pop();
			}
			if(ok)	printf("Yes\n");
			else	printf("No\n");
			scanf("%d", &x);
		}
		printf("\n");
	}

	return 0;
}
