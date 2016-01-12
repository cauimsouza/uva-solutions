#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b)	for(int i = int(a); i <= int(b); i++)


int main(int argc, char const *argv[])
{
	char c, menor;
	int index, cont = 1;
	vector< stack<char> > v;

	while(true){
		c = getchar();
		if(c == 'e')	break;

		v.clear();
		v.reserve(26);
		do{
			menor = 'Z' + 1;
			index = -1;
			for(int j = 0; j < (int)v.size(); j++)
				if(v[j].top() >= c && v[j].top() <= menor){
					menor = v[j].top();
					index = j;
				}
			if(index >= 0)
				v[index].push(c);
			else{
				stack<char> aux;
				aux.push(c);
				v.push_back(aux);
			}
		}while((c = getchar()) != '\n');
		printf("Case %d: %d\n", cont++, (int)v.size());
	}
	return 0;
}
