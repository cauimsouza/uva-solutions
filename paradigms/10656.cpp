#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
typedef vector<int> vi;

int main(){
	int n;
	while(scanf("%d", &n), n){
		bool first = true;
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			if(x){
				if(first) printf("%d", x);
				else printf(" %d", x);
				first = false;
			}
		}
		if(first) printf("0");
		printf("\n");
	}

}
