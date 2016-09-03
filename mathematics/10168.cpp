#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

vector<int> primes;
bitset<10000010> bs;
void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= 10000000; i++)
		if(bs[i]){
			for(long long j = i *i ; j <= 10000000; j += i) bs[j] = 0;
			primes.push_back((int) i);
		}
}

int main(){
	sieve();

	int n;
	while(scanf("%d", &n) != EOF){
		bool can = false;
		for(int i = 0; !can && primes[i] <= n / 4; i++){
			for(int j = i; !can && j < (int) primes.size(); j++){
				if(primes[i] + 3 * primes[j] > n) break;
				for(int k = j; k < (int)primes.size(); k++){
					if(primes[i] + primes[j] + 2 * primes[k] > n) break;
					int sum = primes[i] + primes[j] + primes[k];
					if(bs[n - sum]){
						can = true;
						printf("%d %d %d %d\n", primes[i], primes[j], primes[k], n - sum);
						break;
					}
				}
			}
		}

		if(!can)
			printf("Impossible.\n");
	}
	return 0;
}