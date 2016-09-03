#include <cstdio>
#include <cmath>
#include <sstream>
#include <iostream>
using namespace std;

int main(){
	int testes;
	scanf("%d\n\n", &testes);

	for(int i = 0; i < testes; i++){
		double sum = 0;
		scanf("%*s %*s\n");

		string line;
		while(true){
			getline(cin, line);
			if(line.length() == 0)
				break;
			istringstream is(line);
			int a, b, c, d;
			is >> a >> b >> c >> d;
			sum += 2 * hypot(c - a, d - b);
		}

		sum *= 3;
		sum /= 1000;
		int res = sum;
		if(sum - res > 0.5)
			res++;
		if(i)
			printf("\n");
		printf("%d:%02d\n", res / 60, res % 60);
	}
}