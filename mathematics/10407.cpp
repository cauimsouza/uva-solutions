#include <cstdio>
#include <vector>
#include <algorithm>

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	using namespace std;
	int x;
	while(scanf("%d", &x), x){
		vector<int> vet;
		do{
			vet.push_back(x);
		}while(scanf("%d", &x), x);

		int mdc = 0;
		for(int i = (int) vet.size() - 1; i > 0; i--)
			vet[i] -= vet[0];
		for(int i = (int) vet.size() - 1; i > 0; i--)
			mdc = gcd(vet[i], mdc);
		printf("%d\n", abs(mdc));
	}

	return 0;
}