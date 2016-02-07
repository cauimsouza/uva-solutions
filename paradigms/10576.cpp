#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
int s, d;
int maxSum, bitmask; // 1 profit, 0 deficit

void backtracking(int month, int sumLast){
	if(month >= 4){ // we need to check if we had a deficit in last 5 months
		if(sumLast >= 0) return; 
	}
	if(month >= 11){ // months have index 0...11
		int sum = 0;
		for(int i = 0; i < 12; i++) sum += (bitmask & (1 << i)) ? s : -d;
		if(sum > maxSum) maxSum = sum;
		return; }
	

	int profitFiveMonthsAgo = 0;
	if(month >= 4)
		profitFiveMonthsAgo = (bitmask & (1 << (month - 4) ) ) ? s : -d;
	// profit on this month
	bitmask |= 1 << (1+month);
	backtracking(month + 1, sumLast + s - profitFiveMonthsAgo);
	// deficit of this month
	bitmask ^= 1 << (1+month);
	backtracking(month + 1, sumLast - d - profitFiveMonthsAgo);
}


int main(){

	while(scanf("%d%d", &s, &d) != EOF){
		maxSum = -inf;
		bitmask = 0;
		backtracking(0, -d);
		bitmask = 1;
		backtracking(0, s);

		if(maxSum >= 0) printf("%d\n", maxSum);
		else printf("Deficit\n");
	}

	return 0;
}