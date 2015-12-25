#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k, s = 0;
		scanf("%d%d", &n, &k);
		do{
			if(k >= (1 << (n-1))){
				s += (1 << (n-1));
				k -= (1 << (n-1));
				k = (1 << (n-1)) - k - 1;
			}
			n --;
		//printf("n: %d, k: %d, s: %d\n", n, k, s);
		}while(n);
		cout << s << endl;
	}
}
