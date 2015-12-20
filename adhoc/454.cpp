#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)
#define pb push_back
#define mp	make_pair
#define sz(v) int((v).size())

string funcao(string a){
	char b[1000];
	int i, j = 0;
	for(i = 0; a[i] != '\0'; i++){
		if(!isspace(a[i]))	b[j++] = a[i];
	}
	b[j] = '\0';
	return string(b);
}

int main(){
	int t, i, j, k, cont = 1;
	string frase, reduzida;
	scanf("%d\n\n", &t);

	while(t--){
		if(cont++ > 1) cout << endl;
		vector< pair<string, vector<string> > >anagramas;
		vector<string> res;
		
		getline(cin, frase);
		while(frase.length()){
			string reduzida = funcao(frase);
			sort(reduzida.begin(), reduzida.end());

			for(i = 0; i < sz(anagramas) && anagramas[i].first != reduzida; i++);
			if(i < sz(anagramas))
				anagramas[i].second.pb(frase);
			else{
				vector<string> aux;
				aux.pb(frase);
				anagramas.pb(mp(reduzida, aux));
			}

			getline(cin, frase);
		}

		REC(i, 0, sz(anagramas) - 1)
			sort(anagramas[i].second.begin(), anagramas[i].second.end());

		for(k = 0; k < sz(anagramas); k++){
			if(sz(anagramas[k].second) > 1){
				i = 0;
				while(i < sz(anagramas[k].second)){
					j = i + 1;
					while(j < sz(anagramas[k].second)){
						string aux = anagramas[k].second[i] + " = " + anagramas[k].second[j];
						res.pb(aux);
						j++;
					}
					i++;
				}
			}
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < sz(res); ++i)
		{
			cout << res[i] << endl;
		}
	}
	

	return 0;
}
