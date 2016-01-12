#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int num; // numero de elementos
	while(scanf("%d", &num), num){
		priority_queue<int,vector<int>,greater<int> > pq;
		int custo = 0;

		int x;
		while(num--){
			scanf("%d", &x);
			pq.push(x);
		}

		int a, b;
		while((int)pq.size() > 1){
			a = pq.top(); pq.pop();
			b = pq.top(); pq.pop();
			custo += a + b;
			pq.push(a + b);
		}

		printf("%d\n", custo);
	}
	return 0;
}
