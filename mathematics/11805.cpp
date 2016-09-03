#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int caso;
    scanf("%d", &caso);
    int cas = 1;
    while(caso--){
    	int n, k, p;
        scanf("%d %d %d", &n, &k, &p);
        int res = (k + p) % n;
        if(res == 0)
            res = n;
        printf("Case %d: %d\n", cas++, res);
    }
}
