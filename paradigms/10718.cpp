#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
typedef vector<int> vi;
#define test(s,i) (s & (1 << i))
#define setBit(s,i) (s |= (1 << i))
#define resetBit(s,i) (s &= ~(1 << i))

int main(){
	unsigned n, l, u;
	while(scanf("%u%u%u", &n, &l, &u) != EOF){
		unsigned essential = 0;
		for(int i = 31; i >= 0; i--){
			if(!test(n,i)) setBit(essential,i);
			if(essential > u) resetBit(essential,i);
		}
		int num = 0;
		for(int i = 31; i >= 0; i--){
			if(num < l && test(l,i)) setBit(num, i);
			if(test(essential, i)) setBit(num,i);
			if(num > u) resetBit(num ,i);
		}
		printf("%u\n", num);
	}

}
