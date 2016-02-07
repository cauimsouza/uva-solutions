#include <bits/stdc++.h>
using namespace std;

inline double eq(int p, int q, int r, int s, int t, int u, double x){
	return p*exp(-x) + q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

int main(){

	int p, q, r, s, t, u;
	while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF){
		double lo = 0, hi = 1, mid, yhi, ylo;
		yhi = eq(p,q,r,s,t,u,hi);
		ylo = eq(p,q,r,s,t,u,lo);
		if(yhi * ylo > 0.00005) printf("No solution\n");
		else{
			for(int i = 0; i < 50; i++){
				mid = (lo + hi) / 2;
				double y = eq(p,q,r,s,t,u,mid);
				if(y == 0) break;
				if(y * yhi > 0) hi = mid;
				else lo = mid;  
			}
			printf("%.4f\n", mid);
		}
	}
}