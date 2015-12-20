#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)
#define pb push_back
#define mp	make_pair
#define sz(v) int((v).size())

int main(){
	
	int n;
	scanf("%d", &n);
	while(n--){
		int soma, dif;
		scanf("%d%d", &soma, &dif);
		if(soma < dif || (soma+dif)%2 || (soma-dif)%2)	printf("impossible\n");
		else	printf("%d %d\n", (soma+dif)/2, (soma-dif)/2);
	}
	

	return 0;
}
