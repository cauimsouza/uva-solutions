#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
vll primes;

const ll MAX = 2147483647;

void simpleSieve(){
	ll lim = 46340;
	bitset<46341> bs;
	bs.set();
	for(ll i = 2; i <= lim; i++){
		if(bs[i]){
			for(ll j = i * i; j <= lim; j += i)
				bs[j] = false;
			primes.push_back(i);
		}
	}
}

vll  segmentedSieve(int L, int U){
	if(U <= primes.back()){
		auto first = lower_bound(primes.begin(), primes.end(), L);
		auto last = upper_bound(primes.begin(), primes.end(), U);
		return vll(first, last);
	}
	int square = floor(sqrt(MAX));
	vll ans;

	vector<bool> mark(square, true);
	ll lo = L;
	while(lo <= U){
		ll hi = lo + square;

		fill(mark.begin(), mark.end(), true);
		for(int i = 0; i < (int) primes.size(); i++){
			if(primes[i] >= lo) break;
			ll x = (lo / primes[i]) * primes[i];
			if(x < lo) x += primes[i];
			for(; x <= hi; x += primes[i])
				mark[x - lo] = false; 
		}

		for(ll i = 0; i < square; i++)
			if(mark[i] && i + lo <= U && i + lo > 1) ans.push_back(i + lo);

		lo = hi;
	}

	return ans;
}

int main(){
	simpleSieve();
	int l, u;
	while(scanf("%d %d", &l, &u) != EOF){
		vll vet_primes = segmentedSieve(l, u);

		ll min_dist = MAX, max_dist = -1;
		ll min_idx, max_idx;
		for(int i = 0; i < (int) vet_primes.size() - 1; i++){
			if(vet_primes[i + 1] - vet_primes[i] < min_dist){
				min_dist = vet_primes[i + 1] - vet_primes[i] ;
				min_idx = i;
			}
			if(vet_primes[i + 1] - vet_primes[i] > max_dist){
				max_dist = vet_primes[i + 1] - vet_primes[i] ;
				max_idx = i;
			}
		}

		if(max_dist > 0)
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n", vet_primes[min_idx], vet_primes[min_idx + 1], vet_primes[max_idx], vet_primes[max_idx + 1]);
		else
			printf("There are no adjacent primes.\n");
	}
}