#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

const int LIM = 1e7;

vector<int> primes;
void primesGen(){
	bitset<LIM> bs;
	bs.set();
	for(int i = 2; i<= LIM; i++){
		if(bs[i]){
			primes.push_back(i);
			for(long long j = (long long) i*i; j <= LIM; j += i)
				bs[j] = 0;
		}
	}
}

int main(){
	primesGen();
	int n;
	while(scanf("%d", &n), n){
		for(int i = 0; ;i++){
			int a = primes[i];
			int b = n - a;
			if(binary_search(primes.begin(), primes.end(), b)){
				printf("%d = %d + %d\n", n, a, b);
				break;
			}
		}
	}
}