#include <cstdio>
#include <cstdlib>
using namespace std;

int main(){
	long long a, b;
	while(scanf("%lld %lld", &a, &b) != EOF)
		printf("%lld\n", abs(a-b));
}