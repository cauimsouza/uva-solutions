#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

bitset<1010> bs;
vector<int> primes;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	primes.push_back(1);
	for(int i = 2; i <= 1010; i++){
		if(bs[i]){
			for(int j = i * i; j <= 1010; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int main(){
	sieve();
	int n,  c;
	while(scanf("%d %d", &n, &c) != EOF){
		int num = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
		int inf, sup;
		if(num % 2 == 0){
			inf = max(0, num / 2 - c);
			sup = min(num - 1, num / 2 + c - 1);
		}
		else{
			inf = max(0, num / 2 - c + 1);
			sup = min(num - 1, num / 2 + c - 1);
		}

		printf("%d %d:", n, c);
		for(int i = inf; i <= sup; i++)
			printf(" %d", primes[i]);
		printf("\n\n");
	}
}