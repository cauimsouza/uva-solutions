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

int vet[5];
bool  can(int rem, int sum, int goal){
	if(rem == 1){
		if(bs[goal - sum]){
			vet[3] = goal - sum;
			return true;
		}
		return false;
	}

	for(int i = 0; i < (int) primes.size(); i++){
		if(sum + primes[i] > goal) break;
		if(can(rem - 1, sum + primes[i], goal)){
			vet[4  - rem] = primes[i];
			return true;
		}
	}
	return false;
}

int main(){
	sieve();

	int n;
	while(scanf("%d", &n) != EOF){
		if(!can(4, 0, n))
			printf("Impossible.\n");
		else
			printf("%d %d %d %d\n", vet[0], vet[1], vet[2], vet[3]);
	}
	return 0;
}