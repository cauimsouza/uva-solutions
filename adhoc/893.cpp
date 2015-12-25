#include <bits/stdc++.h>
using namespace std;


int QntdDiasMes(int mes, int ano);
int Dias_prox_ano(int dia, int mes, int ano);

int main(int argc, char const *argv[])
{
	
	int n, dia, mes, ano;
	

	while(scanf("%d%d%d%d", &n, &dia, &mes, &ano), n || dia || mes || ano){
		while(n >= Dias_prox_ano(dia, mes,ano)){
			n -= Dias_prox_ano(dia, mes, ano);
			ano++;
			dia = mes = 1;
		}
		while(n >= QntdDiasMes(mes, ano) - dia + 1){
			n -= QntdDiasMes(mes, ano) - dia + 1;
			mes++;
			dia = 1;
		}
		printf("%d %d %d\n", dia+n, mes, ano);
	}

	return 0;
}

int Dias_prox_ano(int dia, int mes, int ano){
	int soma = QntdDiasMes(mes, ano) - dia + 1;
	for(int i = mes + 1; i < 13; i++){
		soma += QntdDiasMes(i, ano);
	}
	return soma;
}

int QntdDiasMes(int mes, int ano){
	if(mes < 8){
		if(mes%2)	return 31;
		else if(mes == 2){
			if((ano%4 == 0 && ano%100) || ano%400 == 0)	return 29;
			return 28;
		}
		return 30;
	}
	if(mes%2 == 0)	return 31;
	return 30;
}
