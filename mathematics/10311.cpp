#include <cstdio>
#include <bitset>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

vector<int> primes;
bitset<100000010> bs;
void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= 100000000; i++)
		if(bs[i]){
			for(long long j = i *i ; j <= 100000000; j += i) bs[j] = 0;
			primes.push_back((int) i);
		}
}

bool isPrime(int n){
	if(n < 2) return false;
	if(n <= 100000000) return bs[n];
	for(int i = 0; i < (int) primes.size(); i++)
		if(n % primes[i] == 0) return false;
	return true;
}

int main(){
	//clock_t begin = clock();
	sieve();
	//clock_t end = clock();
	//printf("%lf\n", double(end - begin) / CLOCKS_PER_SEC);

	int n;
	while(scanf("%d", &n) != EOF){
		bool can = false;

		if(n % 2){ // odd number, check if n - 2 is prime
			if(isPrime(n - 2)){
				can = true;
				printf("%d is the sum of 2 and %d.\n", n, n - 2);
			}
		}
		else{ // even number, iterate from n / 2 to 0
			int mid = n / 2 - 1;
			int end_id = min(mid, (int) primes.size());
			int i = lower_bound(primes.begin(), primes.begin() + end_id, mid) - primes.begin();
			while(primes[i] >= n / 2) i--;
			for(; i >= 0; i--)
				if(isPrime( n - primes[i] )){
					printf("%d is the sum of %d and %d.\n", n, primes[i], n - primes[i]);
					can = true;
					break;
				}
		}
		if(!can)
			printf("%d is not the sum of two primes!\n", n);
	}
	return 0;
}