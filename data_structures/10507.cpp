#include <bits/stdc++.h>
using namespace std;

#define REC(i, a, b) for(int i = (int)a; i <= (int) b; i++)
typedef vector<int> vi;

int main()
{
	int slept_areas, connections;

	while(scanf("%d %d", &slept_areas, &connections) != EOF){
		bitset<30> isAwake; // bit i set to 1 if region 'A'+i is awake, 0 otherwise
		bitset<30> isSlept; 

		REC(i, 1, 3){
			char c;
			scanf(" %c", &c);
			isAwake.set(c - 'A');
		}

		vector<vi> AdjList(30);
		REC(i, 1, connections){
			char regA, regB;
			scanf(" %c %c", &regA, &regB);
			if(!isAwake.test(regA - 'A')) isSlept.set(regA - 'A'); 
			if(!isAwake.test(regB - 'A')) isSlept.set(regB - 'A'); 
			AdjList[regA - 'A'].push_back(regB - 'A');
			AdjList[regB - 'A'].push_back(regA - 'A');
		}

		slept_areas -= 3;
		int years = 0;
		while(isSlept.any()){
			years++;
			vi justWokeUp;
			for (int i = 0; i < 30; ++i)
			{
				if(isSlept.test(i)){
					int count = 0;
					for(int j = 0; j < (int)AdjList[i].size(); j++){
						if(isAwake[AdjList[i][j]]) count++;
					}
					if(count > 2){
						justWokeUp.push_back(i);
					}
				}
			}
			if(!justWokeUp.size()){
				years = -1;
				break;
			}
			slept_areas -= justWokeUp.size();
			for (int i = 0; i < (int)justWokeUp.size(); ++i)
			{
				isAwake.set(justWokeUp[i]);
				isSlept.reset(justWokeUp[i]);
			}
		}

		if(years == -1 || slept_areas)
			printf("THIS BRAIN NEVER WAKES UP\n");
		else
			printf("WAKE UP IN, %d, YEARS\n", years);
	}

	return 0;
}