#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define lsone(i) (i & (-i))

class FenwickTree{
	vi ft;
public:
	int rmq(int b){
		int sum = 0;
		for(; b; b -= lsone(b))
			sum += ft[b];
		return sum;
	}
	int rmq(int a, int b){
		return rmq(b) - (a == 1 ? 0 : rmq(a - 1));
	}
	void unset(int i){
		for(; i < (int)ft.size(); i += lsone(i)) ft[i] -= 1;
	}
	void set(int i){
		for(; i < (int)ft.size(); i += lsone(i)) ft[i] += 1;
	}
	FenwickTree(int N): ft(N + 1, 0) {}
};

int main(int argc, char const *argv[])
{
	int numbers, queries;
	while(scanf("%d%d", &numbers, &queries) != EOF){
		FenwickTree zer(numbers);
		FenwickTree neg(numbers);
		vi array(numbers + 1);

		for (int i = 1; i <= numbers; ++i)
		 {
		 	scanf("%d", &array[i]);
		 	if(array[i] < 0) neg.set(i);
		 	else if(!array[i]) zer.set(i);
		 } 

		 while(queries--){
		 	char type;
		 	int first, sec;
		 	scanf(" %c%d%d", &type, &first, &sec);

		 	if(type == 'C'){ // change num at pos 'first' to 'sec'
		 		if(array[first] > 0){
		 			if(sec == 0)
		 				zer.set(first);
		 			else if(sec < 0)
		 				neg.set(first);
		 		}
		 		else if(array[first] == 0){
		 			if(sec > 0)
		 				zer.unset(first);
		 			else if(sec < 0){
		 				zer.unset(first);
		 				neg.set(first);
		 			}
		 		}
		 		else{
		 			if(sec == 0){
		 				zer.set(first);
		 				neg.unset(first);
		 			}
		 			else if(sec > 0)
		 				neg.unset(first);
		 		}
		 		array[first] = sec;
		 	}
		 	else{
		 		if(zer.rmq(first, sec)) printf("0");
		 		else if(neg.rmq(first,sec)%2) printf("-");
		 		else printf("+");
		 	}
		 }
		 printf("\n");
	}
	return 0;
}
