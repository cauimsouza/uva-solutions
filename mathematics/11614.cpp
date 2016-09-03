#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    long long n;
    int casos;
    scanf("%d", &casos);
    while(casos--){
        scanf("%lld", &n);
        printf("%lld\n", (long long)(-1.0/2 + sqrt(1.0 /4 + 2 * n )) );
    }
}
