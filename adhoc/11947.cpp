#include <bits/stdc++.h>
using namespace std;


int QntdDiasMes(int mes, int ano);
int Dias_prox_ano(int dia, int mes, int ano);

int main(int argc, char const *argv[])
{
	
	int n, dia, mes, ano;
	int t, cont = 1; // casos teste
	string inp;
	cin >> t;

	while(t--){
		cin >> inp;
		mes = (inp[0]-'0')*10 + inp[1]-'0';
		dia = (inp[2]-'0')*10 + inp[3]-'0';
		ano = (inp[4]-'0')*1000 + (inp[5]-'0')*100 + (inp[6]-'0')*10 + inp[7]-'0';
		n = 40*7;
		
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
		dia += n;
		printf("%d %02d/%02d/%d ", cont++, mes, dia, ano);
		if((dia >= 21 && mes == 1) || (dia <= 19 && mes == 2))	cout << "aquarius\n";
		else if((dia >= 20 && mes == 2) || (dia <= 20 && mes == 3))	cout << "pisces\n";
		else if((dia >= 21 && mes == 3) || (dia <= 20 && mes == 4))	cout << "aries\n";
		else if((dia >= 21 && mes == 4) || (dia <= 21 && mes == 5))	cout << "taurus\n";
		else if((dia >= 22 && mes == 5) || (dia <= 21 && mes == 6))	cout << "gemini\n";
		else if((dia >= 22 && mes == 6) || (dia <= 22 && mes == 7))	cout << "cancer\n";
		else if((dia >= 23 && mes == 7) || (dia <= 21 && mes == 8))	cout << "leo\n";
		else if((dia >= 22 && mes == 8) || (dia <= 23 && mes == 9))	cout << "virgo\n";
		else if((dia >= 24 && mes == 9) || (dia <= 23 && mes == 10))	cout << "libra\n";
		else if((dia >= 24 && mes == 10) || (dia <= 22 && mes == 11))	cout << "scorpio\n";
		else if((dia >= 23 && mes == 11) || (dia <= 22 && mes == 12))	cout << "sagittarius\n";
		else cout << "capricorn\n";
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
