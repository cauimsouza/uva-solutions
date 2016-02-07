#include <bits/stdc++.h>
using namespace std;

int main(){
	int TC;
	int niceness[20010];
	scanf("%d", &TC);
	for (int cont = 1; cont <= TC; ++cont)
	{
		int s;
		scanf("%d", &s);
		for(int i = 1; i < s; i++) scanf("%d", &niceness[i]);

		int sum = 0, maxSum = 0, first = -1, last = -1, j = 1;
		for(int i = 1; i < s; i++){
			sum += niceness[i];
			if(sum > maxSum){
				maxSum = sum;
				first = j;
				last = i;
			}
			else if(sum == maxSum && i - j > last - first){
				last = i;
				first = j;
			}
			else if(sum < 0){
				j = i + 1;
				sum = 0;
			}
		}

		if(first == -1) printf("Route %d has no nice parts\n", cont);
		else printf("The nicest part of route %d is between stops %d and %d\n", cont, first, ++last);
	}
}