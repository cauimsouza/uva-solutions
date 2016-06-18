#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;


int main(){
	int n;
	map<int, int> indices;
	vector<int> seq;
	vector<int> qnt;
	while(scanf("%d", &n) != EOF){
		map<int, int>::iterator it = indices.find(n);
		if(it == indices.end()){
			seq.push_back(n);
			qnt.push_back(1);
			indices[n] = seq.size() - 1;
		}
		else
			qnt[it->second]++;
	}

	for(int i = 0; i < qnt.size(); i++){
		printf("%d %d\n", seq[i], qnt[i]);
	}
}