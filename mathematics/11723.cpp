#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int n, r;
    int caso = 1;
    while(scanf("%d %d", &r, &n), n ){
    	printf("Case %d: ", caso++);
    	int res = r / n;
    	if(r % n == 0)
    		res--;
    	if(res > 26)
    		printf("impossible\n");
    	else
    		printf("%d\n", res);

    }
}
