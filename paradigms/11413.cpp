#include <bits/stdc++.h>
using namespace std;

#define inf (int)1e9 + 10

int vessels, containers;
int array[1010]; 
bool can(int cap){
	int cont = 1, left = cap;
	for(int i = 0; i < vessels; i++){
		if(cap < array[i]) return false;
		if(left < array[i]){
			cont++;
			left = cap;
		}
		left -= array[i];
		if(cont > containers) return false;
	}
	return true;
}

int main(){
	
	while(scanf("%d%d", &vessels, &containers) != EOF){
		for(int i = 0; i < vessels; i++)
			scanf("%d", &array[i]);
		int lo = 1, hi = inf, mid, ans;
		while(hi > lo){
			mid = (lo + hi) / 2;
			if(can(mid)) { hi = mid; ans = mid; }
			else lo = mid + 1;
		}
		printf("%d\n", ans);
	}
}