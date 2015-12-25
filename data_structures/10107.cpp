#include <bits/stdc++.h>
using namespace std;

#define ALL(v) (v).begin(), (v).end()

int main(int argc, char const *argv[])
{
	
	int x; // novo elemento a ser adicionado
	int cont = 0, pos; // numero de elementos
	vector<int> v;
	int m1, m2;

	while(scanf("%d", &x) != EOF){
		v.push_back(x);
		cont++;
		pos = cont/2;
		nth_element(v.begin(), v.begin()+pos, v.end());
		m1 = *(v.begin()+pos);
		if(cont%2){
				printf("%d\n", m1);
		}
		else{
			nth_element(v.begin(), v.begin()+pos-1, v.end());
			m2 = *(v.begin()+pos-1);
			printf("%d\n", (m1 + m2)/2);
		}
	}

	return 0;
}
