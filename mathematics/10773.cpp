#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int casos;
	scanf("%d",&casos);
	for (int casono = 0; casono < casos; ++casono)
	{
		printf("Case %d: ", casono + 1);
		int d, u, v;
		scanf("%d %d %d", &d, &v, &u);
		if(u <= v || v == 0)
			printf("can't determine\n");
		else{
			printf("%.3f\n", d / (sqrt(u*u-v*v)) - d / (u*1.0));
		}
	}
}