#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

int gcd(int a, int b){
	return b == 0 ? a : gcd(b, a % b);
}

int main(){
	using namespace std;

	int tests;
	scanf("%d\n", &tests);
	while(tests--){
		string line;
		getline(cin, line);
		istringstream sstring(line);

		vector<int> vet;
		int x;
		while(sstring >> x) vet.push_back(x);

		sort(vet.begin(), vet.end());

		int max_gcd = -1;
		for(int i = 0; i < (int)vet.size(); i++){
			for(int j = i + 1; j < (int) vet.size(); j++){
				int x = gcd(vet[j], vet[i]);
				max_gcd = max(max_gcd, x);
			}
		}

		printf("%d\n", max_gcd);
	}

	return 0;
}