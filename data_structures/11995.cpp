#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF){
		stack<int> p;
		queue<int> q;
		priority_queue<int> pq;
		bool isStack, isQueue, isPQ;
		isPQ = isQueue = isStack = true;

		int x;
		while(n--){
			scanf("%d", &x);
			if(x == 1){ // inserir na estrutura de dados
				scanf("%d", &x);
				if(isStack)	p.push(x);
				if(isQueue) q.push(x);
				if(isPQ) pq.push(x);
			}
			else{// extrair da estrutura de dados
				scanf("%d", &x);
				if(isStack && !p.empty()){
					isStack = isStack && (p.top() == x);
					p.pop();
				}
				else
					isStack = false;
				if(isQueue && !q.empty()){
					isQueue = isQueue && (q.front() == x);
					q.pop();
				}
				else
					isQueue = false;
				if(isPQ && !pq.empty()){
					isPQ = isPQ && (pq.top() == x);
					pq.pop();
				}
				else
					isPQ = false;
			}
		}

		int cont = 0;
		if(isPQ) cont++;
		if(isQueue) cont++;
		if(isStack) cont++;

		if(cont == 0)
			printf("impossible\n");
		else if(cont > 1)
			printf("not sure\n");
		else if(isStack)
			printf("stack\n");
		else if(isPQ)
			printf("priority queue\n");
		else
			printf("queue\n");
	}
	return 0;
}
