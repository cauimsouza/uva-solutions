#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int num, den;
	vector<int> lista;
	while(scanf("%d %d", &num, &den) != EOF){
		lista.clear();
		if(num % den == 0){
			printf("[%d]\n", num / den);
		}
		else{
			if(num == 1){
				lista.push_back(0);
				lista.push_back(den);
			}
			else{
				while(num != 1){
					int resto = num % den;
					int quo = num / den;
					lista.push_back(quo);
					if(resto == 0)
						break;
					num = den;
					den = resto;
					for(int i = 2; i <= resto; i++)
						if(num % i == 0 && den % i == 0) num /= i, den /= i;
				}
			}
			printf("[%d;", lista.front());
			for(int i = 1; i < (int) lista.size() - 1; i++)
				printf("%d,", lista[i]);
			printf("%d]\n", lista.back());
		}
	}

	return 0;
}