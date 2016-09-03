#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

vector<int> primes;

void sieve(){
	bitset<1000001> bs;
	bs.set();
	for(long long i = 2; i <= 1000000; i++)
		if(bs[i]){
			for(long long j = i * i; j <= 1000000; j += i) bs[j] = 0;
			primes.push_back(i);
		}
}

int main(){
	sieve();
	long long n;
	while(scanf("%lld", &n), n){
		n = abs(n);
		long long high = -1;
		int cont = 0;
		int pf_id = 0, pf = primes[pf_id];
		while(pf * pf <= n){
			if(n % pf == 0){
				while(n % pf == 0)
					n /= pf;
				high = pf;
				cont++;
			}
			++pf_id;
			if(pf_id >= primes.size()) break;
			pf = primes[pf_id];
		}
		if(n > 1){
			high = n;
			cont++;
		}
		if(cont <= 1) printf("-1\n");
		else printf("%lld\n", high);
	}

	return 0;
}