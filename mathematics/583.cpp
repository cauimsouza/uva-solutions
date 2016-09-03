#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

vector<int> primes;

void sieve(){
	bitset<100001> bs;
	bs.set();
	for(long long i = 2; i <= 100000; i++)
		if(bs[i]){
			for(long long j = i * i; j <= 100000; j += i) bs[j] = 0;
			primes.push_back(i);
		}
}

void primeFactors(vector<int>& v, int N){
	v.clear();
	int PF_idx = 0, PF = primes[0];
	while(PF * PF <= N){
		if(N % PF == 0){
			do{
				N /= PF;
				v.push_back(PF);
			}while(N % PF == 0);
		}
		if(++PF_idx == (int) primes.size()) break;
		PF = primes[PF_idx];
	}
	if(N > 1){
		v.push_back(N);
	}
}


int main(){
	sieve();
	int n;
	while(scanf("%d", &n), n){
		vector<int> v;
		primeFactors(v, abs(n));
		printf("%d = ", n);
		if(n < 0) printf("-1 x ");
		for(int i = 0; i < (int) v.size() - 1; i++)
			printf("%d x ", v[i]);
		printf("%d\n", v.back());
	}

	return 0;
}