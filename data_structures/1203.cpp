#include <bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int> > iii;
#define mp make_pair

int main(int argc, char const *argv[])
{
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	string input;
	int id, periodo, k, tempo;

	cin >> input;
	while(input != "#"){
		scanf("%d%d", &id, &periodo);
		pq.push(mp(periodo,mp(id,periodo)));
		cin >> input;
	} 
	scanf("%d", &k);
	while(k--){
		tempo = pq.top().first;
		id  = pq.top().second.first;
		periodo = pq.top().second.second;
		printf("%d\n", id);
		pq.pop();
		pq.push(mp(tempo+periodo,mp(id,periodo)));
	}

	return 0;
}
