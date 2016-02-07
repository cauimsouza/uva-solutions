#include <bits/stdc++.h>
using namespace std;

#define chartoi(c) ((c) >= 'a' ? (c) - 'a' + 26 : (c) - 'A')
#define pb push_back
#define all(v) (v).begin(), (v).end()
typedef vector<int> vi;

int main(){
	int i = 0;
	vector<vi> indexList(60, vi());
	vi::iterator it;
	char c;

	while((c = getchar()) != '\n')
		indexList[chartoi(c)].pb(i++);

	int queries;
	scanf("%d", &queries);
	while(queries--){
		scanf(" %c", &c);
		bool fail = false;
		int Begin, End;

		Begin = End = indexList[ chartoi(c) ][0];
		c = getchar(); 
		while(c != '\n' && c != EOF){
			if(!fail){
				it = upper_bound( all(indexList[ chartoi(c) ]) , End);
				if(it == indexList[ chartoi(c) ].end()) fail = true;
				else
					End = *it;
			}
			c = getchar();
		}

		if(fail) printf("Not matched\n");
		else
			printf("Matched %d %d\n", Begin, End);
	}

	return 0;
}
