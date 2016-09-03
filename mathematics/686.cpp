#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

bitset<32768> bs;
vector<int> primes;

void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(int i = 2; i <= 32768; i++){
		if(bs[i]){
			for(int j = i * i; j <= 32768; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
	}
}

int main(){
	sieve();
	int n;
	while(scanf("%d", &n), n){
		int ans = 0;
		for(int i = 0; i < (int) primes.size(); i++){
			int p = primes[i];
			if(p > n / 2) break;
			if(bs[n - p]) ans++;
		}
		printf("%d\n", ans);
	}
}