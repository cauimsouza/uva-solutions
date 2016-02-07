#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()

int main(){
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int M;
		vector<pair<int,int> > inters;
		scanf("%d", &M);
		inters.clear();
		while(true){
			int a, b;
			scanf("%d%d", &a, &b);
			if(a == 0 && b == 0) break;
			inters.push_back(make_pair(a, b));
		}

		sort(inters.begin(), inters.end());

		int lim = 0, i = 0;
		vector<int> idx;
		while(lim < M && i < sz(inters)){
			int maior = lim, k;
			for(int j = i + 1; j < sz(inters) && inters[j].first <= lim; j++){
				if(inters[j].second > maior){
					maior = inters[j].second;
					k = j;
				}
			}
			if(maior == lim) break;
			lim = maior;
			idx.push_back(k);
			i = k;
		}


		if(lim < M) printf("0\n");
		else{
			printf("%d\n", sz(idx));
			for(int i = 0; i < sz(idx); i++) printf("%d %d\n", inters[idx[i]].first, inters[idx[i]].second);
		}
		if(casos) printf("\n");
	}
}