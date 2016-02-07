#include <bits/stdc++.h>
using namespace std;

#define x(a) (a).first
#define y(a) (a).second.first
#define z(a) (a).second.second
#define pb push_back
#define mp make_pair

bool ordena(const pair<int,pair<int,int> > &a,const pair<int,pair<int,int> > &b){
	if(x(a) != x(b)) return x(a) > x(b);
	if(y(a) != y(b)) return y(a) > y(b);
	return z(a) > z(b);
}

int main(){
	int n, cont = 1;
	vector<pair<int,pair<int,int> > > ve;
	while(scanf("%d", &n), n){
		ve.clear();
		for(int i = 0; i < n; i++){
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			ve.pb(mp(a,mp(b,c)));
			ve.pb(mp(a,mp(c,b)));
			ve.pb(mp(b,mp(a,c)));
			ve.pb(mp(b,mp(c,a)));
			ve.pb(mp(c,mp(a,b)));
			ve.pb(mp(c,mp(b,a)));
		}
		sort(ve.begin(),ve.end(), ordena);

		vector<int> lis(ve.size());
		int result = 0;
		for(int i = 0; i < (int)ve.size(); i++){
			lis[i] = z(ve[i]);
			for(int j = 0; j < i; j++){
				if(x(ve[j]) > x(ve[i]) && y(ve[j]) > y(ve[i]) && lis[j] + z(ve[i]) > lis[i]){
					lis[i] = lis[j] + z(ve[i]);
				}
			}
			result = max(result, lis[i]);
		}

		printf("Case %d: maximum height = %d\n", cont++, result);		
	}
}