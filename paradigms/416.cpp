#include <bits/stdc++.h>
using namespace std;

#define CharToInt(c) ((c) == 'Y' ? 1 : 0)
#define Test(s,i) ((s) & (1 << i))
#define Set(s,i) ((s) |= (1 << i))
int digit[][7] = {
	{1,1,1,1,1,1,0}, // 0
	{0,1,1,0,0,0,0}, // 1
	{1,1,0,1,1,0,1}, // 2
	{1,1,1,1,0,0,1}, // 3
	{0,1,1,0,0,1,1}, // 4
	{1,0,1,1,0,1,1}, // 5
	{1,0,1,1,1,1,1}, // 6
	{1,1,1,0,0,0,0}, // 7
	{1,1,1,1,1,1,1}, // 8
	{1,1,1,1,0,1,1}  // 9
};
bool match;
int burned, n;
char sequence[15][10];

bool digitMatch(int dig, int idx){
	for(int i = 0; i < 7; i++){
		if(!digit[dig][i] && CharToInt(sequence[idx][i]))
			return false;
		if(CharToInt(sequence[idx][i]) && Test(burned,i))
			return false;
	}
	return true;
}

/**
 * recursive backtracking solution to the problem
 * @param idx  next sequence index to analyze
 * @param last last digit
 */
void backtracking(int idx, int last){
	if(idx == n){
		match = true; return;}
	if(last == 0) return;

	last--;
	if(digitMatch(last, idx)){
		int justBurned = 0;
		for(int j = 0; j < 7; j++){
			if(digit[last][j] && !CharToInt(sequence[idx][j]) && !Test(burned, j))
				Set(justBurned, j);
		}
		burned |= justBurned;
		backtracking(idx + 1, last);
		burned ^= justBurned;
	}
	
}

int main(){
	while(scanf("%d", &n), n){
		for(int i = 0; i < n; i++) scanf("%s", sequence[i]);
		match = burned = 0;
		for(int i = 10; !match && i >= 0; i--)
			backtracking(0, i);
		if(match) printf("MATCH\n");
		else printf("MISMATCH\n");
	}

	return 0;
}
