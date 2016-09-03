#include <cstdio>
#include <utility>
#include <list>
#include <vector>
using namespace std;

const int MAXN = 50; // max number of colours

using ii = pair<int,int>;
using vii = vector<ii>;
using vvii = vector<vii>;

vvii adjlist;
list<int> cyc;

void EulerTour(list<int>::iterator i, int u)
{
	for(int j = 0; j < (int) adjlist[u].size(); j++)
	{
		ii &v = adjlist[u][j];
		if(v.second)
		{
			v.second = 0;
			for(int k = 0; k < (int)adjlist[v.first].size(); k++)
			{
				ii &uu = adjlist[v.first][k];
				if(uu.first == u && uu.second == 1)
				{
					uu.second = 0;
					break;
				}
			}
			EulerTour(cyc.insert(i, u), v.first);
		}
	}
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("entrada", "r", stdin);
	//freopen(fo, "w", stdout);
	#else
	// online submission
	#endif

	int tests;
	scanf("%d", &tests);
	for (int caso = 0; caso < tests; ++caso)
	{
		if(caso)
			printf("\n");
		printf("Case #%d\n", caso + 1);

		int n;
		scanf("%d", &n);
		adjlist.assign(MAXN, vii());
		for(int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			adjlist[a - 1].push_back(ii(b - 1, 1));
			adjlist[b - 1].push_back(ii(a - 1, 1));
		}

		bool isEulerian = true;
		for (int i = 0; i < MAXN; ++i)
		{
			if(adjlist[i].size() % 2)
			{
				isEulerian = false;
				break;
			}
		}

		if(isEulerian)
		{
			int initVertex;
			for(initVertex = 0; initVertex < MAXN; initVertex++)
				if(adjlist[initVertex].size())
					break;

			cyc.clear();
			EulerTour(cyc.begin(), initVertex);
			auto it = cyc.begin();
			auto final = cyc.end();
			final--;
			while(it != final)
			{
				printf("%d ", *it + 1);
				it++;
				printf("%d\n", *it + 1);
			}
			printf("%d %d\n", cyc.back() + 1, cyc.front() + 1);
		}
		else
		{
			printf("some beads may be lost\n");
		}
	}
	return 0;
}