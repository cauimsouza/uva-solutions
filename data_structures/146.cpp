#include <bits/stdc++.h>
using namespace std;

#define REC(i,a,b) for(int i = int(a); i <= int(b); i++)

int main(){
	string input;
	while(true){
		cin >> input;
		if(input == "#")
			break;
		if(next_permutation(input.begin(), input.end()))
			cout << input << endl;
		else
			printf("No Successor\n");
	}

	return 0;
}
