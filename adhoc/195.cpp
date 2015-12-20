#include <bits/stdc++.h>
using namespace std;

char LC(char c){
	if(c >= 'a' && c <= 'z')	return c;
	else	return c - 'A' + 'a';
}

bool funcao(char a, char b){
	if(LC(a) < LC(b))	return true;
	else if(LC(a) == LC(b)){
		return (a != LC(a)) && (b == LC(b));
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	string entrada;
	set<string> conj;

	while(n--){
		conj.clear();
		cin >> entrada;
		sort(entrada.begin(), entrada.end(), funcao);

		do{
			if(conj.find(entrada) == conj.end()){
				cout << entrada << endl;
				conj.insert(entrada);
			}
		}while(next_permutation(entrada.begin(), entrada.end(), funcao));
	}
	return 0;
}
