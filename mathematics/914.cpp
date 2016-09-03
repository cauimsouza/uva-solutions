#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> primes;
bitset<1000010> bs;
void sieve(){
	bs.set();
	bs[0] = bs[1] = 0;
	for(long long i = 2; i <= 1000000; i++)
		if(bs[i]){
			for(long long j = i *i ; j <= 1000000; j += i) bs[j] = 0;
			primes.push_back((int) i);
		}
}

int main(){
	sieve();

	int cases_num;
	scanf("%d", &cases_num);
	while(cases_num--) {
	    	int l, u;
	    	scanf("%d %d", &l, &u);
	    	int a = lower_bound(primes.begin(), primes.end(), l) - primes.begin();
	    	int b = upper_bound(primes.begin(), primes.end(), u) - primes.begin();
	    	map<int,int> freq;
	    	for(; a < b - 1; a++){
	    		int dif = primes[a + 1] - primes[a];
	    		auto it = freq.find(dif);
	    		if(it == freq.end())
	    			freq[dif] = 1;
	    		else
	    			(it->second)++;
	   	 }

	    if(freq.empty())
	    	printf("No jumping champion\n");
	    else{
	    	auto it_max = freq.begin();
	    	int max_freq = -1;
	    	int cont;
	    	for(auto it = freq.begin(); it != freq.end(); it++)
	    		if(it->second > max_freq){
	    			it_max = it;
	    			cont = 1;
	    			max_freq = it->second;
	    		}
	    		else if(it->second == max_freq)
	    			cont++;
	    	

	    	if(cont == 1)
	    		printf("The jumping champion is %d\n", it_max->first);
	    	else
	    		printf("No jumping champion\n");
	    }
	}

	return 0;
}