#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

bitset<20000010> bs;
vector<int> primes;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= 20000000; i++){
		if(bs[i]){
			for(long long j = i * i; j <= 20000000; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int main(){
	sieve();
	vector<int> twin;
	for(int i = 0; i < (int) primes.size() - 1; i++)
		if(primes[i + 1] - primes[i] == 2)
			twin.push_back(primes[i]);
	int n;
	while(scanf("%d", &n) != EOF){
		if(n > (int)twin.size()) while(1);
		printf("(%d, %d)\n", twin[n - 1], twin[n - 1] + 2);
	}
}