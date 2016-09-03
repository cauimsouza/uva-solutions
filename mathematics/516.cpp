#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <utility>

using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;

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

void primeFactors(vii& v, int N){
	int PF_idx = 0, PF = primes[0];
	while(PF * PF <= N){
		if(N % PF == 0){
			int cont = 0;
			do{
				N /= PF;
				cont++;
			}while(N % PF == 0);
			v.push_back(ii(PF, cont));
		}
		if(++PF_idx == (int) primes.size()) break;
		PF = primes[PF_idx];
	}
	if(N > 1){
		v.push_back(ii(N, 1));
	}
}


int main(){
	sieve();
	int base;
	while(scanf("%d", &base), base){
		int sum;
		int expo;
		char c;
		scanf("%d%c", &expo, &c);
		sum = pow(base, expo);
		while(c != '\n'){
			scanf("%d %d%c", &base, &expo, &c);
			sum *= pow(base, expo);
		}
		vii ans;
		primeFactors(ans, sum - 1);
		for(int i = (int) ans.size() - 1; i >= 0; i--){
			printf("%d %d", ans[i].first, ans[i].second);
			if(i)
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}