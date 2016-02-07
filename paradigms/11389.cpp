#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, d, r;
	int morning[110], evening[110];
	while(scanf("%d%d%d", &n, &d, &r), n){
		for(int i = 0; i < n; i++) scanf("%d", &morning[i]);
		for(int i = 0; i < n; i++) scanf("%d", &evening[i]);
		sort(morning, morning + n);
		sort(evening, evening + n);
		int sum = 0;
		for(int i = 0;  i < n; i++){
			int hours = morning[i] + evening[n - i - 1];
			sum += (hours  <= d ? 0 : (hours - d) * r);
		}
		printf("%d\n", sum);
	}
}