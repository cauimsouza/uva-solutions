#include <bits/stdc++.h>
using namespace std;

struct jato{
	double esq, dir;
	bool operator < (const jato &A){
		if(esq != A.esq) return esq < A.esq;
		return dir > A.dir;
	}
};

int main(){
	long long n, l, w;
	while(scanf("%lld%lld%lld", &n, &l, &w) != EOF){
		jato *vet = new jato[n+10];
		for(int i = 0; i < n; i++){
			long long pos, radius;
			scanf("%lld%lld", &pos, &radius);
			double dx;
			if(radius <= w/2)
				dx = 0;
			else 
				dx = sqrt((double)radius*radius - (w/2.0)*(w/2.0));
			vet[i].esq = pos - dx;
			vet[i].dir = pos + dx;
		}
		sort(vet, vet + n);

		long long cont = 0, idx = 0;
		double lim = 0;
		while(lim < l){
			double maior = 0;
			long long i;
			for(i = idx; i < n && vet[i].esq <= lim; i++){
				if(vet[i].dir > maior){
					maior = vet[i].dir;
					idx = i;
				}
			}
			lim = maior;
			cont++;
			idx++;
			if(idx >= n)
				break;
		}

		if(lim < l)
			printf("-1\n");
		else
			printf("%lld\n", cont);

		delete[]vet; 
	}
}