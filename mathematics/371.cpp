#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;

const int MAX = 1000000;

int pd[MAX];
int solve(unsigned int x){
	if(x == 1)
		return 0;
	int a;
	if(x < MAX){
		int a = pd[x];
		if(a > 0)
			return a;
	}
	if(x % 2)
		a = 1 + solve(3 * x + 1);
	else
		a = 1 + solve(x / 2);
	if(x < MAX)
		pd[x] = a;
	return a;
}

int main(){
	int l, h;
	
	memset(pd, -1, sizeof pd);
	while(scanf("%d %d", &l, &h), l){
		int hi = -1;
		int id = -1;
		if(l > h)
			swap(l, h);
		int i = l;
		if(l == 1){
			hi = 3;
			id = 1;
			i++;
		}
		for(; i <= h; i++){
			int x = solve(i);
			if(x > hi){
				hi = x;
				id = i;
			}
		}

		printf("Between %d and %d, %d generates the longest sequence of %d values.\n", l, h, id, hi);
	}

	return 0;
}