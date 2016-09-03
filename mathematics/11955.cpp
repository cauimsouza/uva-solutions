#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

long long coef[55][55];

void binCoef(){
	coef[0][0] = 1;
	for(int i = 1; i <= 50; i++){
		coef[i][0] = 1;
		for(int j = 1; j < i; j++){
			coef[i][j] = coef[i-1][j] + coef[i-1][j-1];
		}
		coef[i][i] = 1;
	}
}

int main(){
	int tests;
	scanf("%d", &tests);

	binCoef();

	for(int case_no = 1; case_no <= tests; case_no++){
		printf("Case %d: ", case_no);

		string input;
		cin >> input;
		int soma_pos = input.find('+');
		int pow_pos = input.find('^');
		string var1 = input.substr(1, soma_pos - 1);
		string var2 = input.substr(soma_pos + 1, pow_pos - soma_pos - 2);
		int pot = stoi(input.substr(pow_pos + 1));

		if(pot == 1){
			printf("%s+%s\n", var1.data(), var2.data());
		}
		else{
			printf("%s^%d", var1.data(), pot);
			for(int i = 1; i < pot; i++){
				printf("+%lld*%s", coef[pot][i], var1.data());
				if(pot - i > 1)printf("^%d", pot - i);
				printf("*%s", var2.data());
				if(i > 1) printf("^%d", i);
			}
			printf("+%s^%d\n", var2.data(), pot);
		}
	}
}