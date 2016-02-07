#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
typedef vector<int> vi;

int main(){
	int bach, spl, k = 1;
	int menor;
	while(scanf("%d%d", &bach, &spl) != EOF){
		if(bach == 0 && spl == 0) break;
		menor = 1e9;
		for(int i = 0; i < bach; i++){
			int x;
			scanf("%d", &x);
			if(x < menor) menor = x;
		}
		for(int i = 0; i < spl; i++) scanf("%*s");
		printf("Case %d:", k++);
		if(bach <= spl) printf(" 0\n");
		else printf(" %d %d\n",  bach - spl, menor);
	}

}
