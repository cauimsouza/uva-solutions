#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)
#define pb push_back
#define mp	make_pair
#define sz(v) int((v).size())

int main(){
	
	int n;
	while(scanf("%d", &n), n){
		
		if(n == 1){
			printf("Printing order for 1 pages:\nSheet 1, front: Blank, 1\n");
			continue;
		}
		printf("Printing order for %d pages:\n", n);
		int sheets;
		if(n%4) sheets = n/4 + 1;
		else	sheets = n/4;
		REC(i, 1, sheets){
			if(4*sheets - (i-1)*2 > n )
				printf("Sheet %d, front: Blank, ", i);
			else
				printf("Sheet %d, front: %d, ", i, 4*sheets - (i-1)*2);
			printf("%d\n", (i-1)*2 + 1);

			if((i-1)*2 + 2 > n)
				printf("Sheet %d, back : Blank, ", i);
			else
				printf("Sheet %d, back : %d, ", i, (i-1)*2 + 2);
			if(4*sheets - (i-1)*2 - 1 > n)
				printf("Blank\n");
			else
				printf("%d\n", 4*sheets - (i-1)*2 - 1);
		}
	}
	

	return 0;
}
