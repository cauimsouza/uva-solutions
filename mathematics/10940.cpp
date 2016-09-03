#include <cstdio>
using namespace std;

inline int LSOne(int S){
	return S & (-S);
}

int main(){
	int n;
	while(scanf("%d", &n), n){
		int ans;
		if(n == LSOne(n))
			ans  = n;
		else{
			int i;
			for(i = 0;; i++)
				if((1 << i) > n) break;
			i--;
			ans = ((n - (1 << i)) << 1);
		}
		printf("%d\n", ans);
	}
}