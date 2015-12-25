#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

int main(int argc, char const *argv[])
{
	
	int n, a, b;
	while(scanf("%d", &n), n){
		a = b = 0;
		int par = 0;
		for(int i = 0; i < 31; i++){
			if(n & (1 << i)){
				if(par%2)
					b += (1 << i);
				else
					a += (1 << i);
				par++;
			}
		}
		printf("%d %d\n", a, b);
	}

	return 0;
}
