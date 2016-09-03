#include <cstdio>
#include <cstring>
#include <vector>
#include <bitset>
using namespace std;

#define MAX 10000
#define MAX_PHI 2000000
vector<int> prime;

int dp_depth[2000001];
int dp_phi[2000001];
long long dp_sum[2000001]; 

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

int phiEuler(int N){
	int &ans = dp_phi[N];
	if(ans != -1)
		return ans;
	ans = N;
	long long pf_id = 0, pf = prime[pf_id];
	while(pf * pf <= N){
		if(N % pf == 0){
			ans -= ans / pf;
			while(N % pf == 0)
				N /= pf;
		}
		pf_id++;
		if(pf_id >= prime.size()) break;
		pf = prime[pf_id];
	}
	if(N > 1)
		ans -= ans / N;
	return ans;
}

int depth(int n){
	if(n == 1)
		return 0;
	int &a = dp_depth[n];
	if(a != -1)
		return a;

	return a = 1 + depth(phiEuler(n));
}

int main(){
	sieve();
	memset(dp_depth, -1, sizeof dp_depth);
	memset(dp_phi, -1, sizeof dp_phi);

	dp_sum[0] = dp_sum[1] = 0;
	for(int i = 2; i <=2000000 ; i++){
		dp_sum[i] = dp_sum[i - 1] + depth(i);
	}

	int n;
	scanf("%d", &n);
	while(n--){
		int l, u;
		scanf("%d %d", &l, &u);

		printf("%lld\n", dp_sum[u] - dp_sum[l - 1]);
	}
}