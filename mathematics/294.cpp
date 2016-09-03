#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

#define MAX 100000
vector<int> prime;

void sieve(){
	bitset<MAX + 10> bs;
	bs.set();
	for(long long i = 2; i <= MAX; i++)
		if(bs[i]){
			prime.push_back(i);
			for(long long j = i * i; j <= MAX; j += i)
				bs[j] = 0;
		}
}

int numDiv(int N){
	int ans = 1;
	long long pf_id = 0, pf = prime[pf_id];
	while(pf * pf <= N){
		if(N % pf == 0){
			int cont = 0;
			while(N % pf == 0){
				cont++;
				N /= pf;
			}
			ans *= (cont + 1);
		}
		pf_id++;
		if(pf_id >= prime.size()) break;
		pf = prime[pf_id];
	}
	if(N > 1)
		ans *= 2;
	return ans;
}

int main(){
	sieve();
	
	int n;
	scanf("%d", &n);
	while(n--){
		int l, u;
		scanf("%d %d", &l, &u);

		int ans, hi = -1;
		for(int i = l; i <= u; i++){
			int x = numDiv(i);
			if(x > hi){
				hi = x;
				ans = i;
			}
		}

		printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, ans, hi);
	}
}