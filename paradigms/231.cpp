#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>; 

int main(){
	int h, cont = 0;
	vi alturas;
	vi lis;
	while(scanf("%d", &h), h != -1){
		if(cont++) printf("\n");
		alturas.clear();
		alturas.push_back(h);
		while(scanf("%d", &h), h != -1) alturas.push_back(h);
		lis.resize(alturas.size());
		int resp = 0;
		for(int i = 0; i < (int)alturas.size(); i++){
			lis[i] = 1;
			for(int j = 0; j < i; j++)
				if(alturas[j] >= alturas[i]) lis[i] = max(lis[i], lis[j] + 1);
			resp = max(resp, lis[i]);
		}
		printf("Test #%d:\n", cont);
		printf("  maximum possible interceptions: %d\n", resp);
	}
}