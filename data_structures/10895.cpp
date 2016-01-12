#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){

	int rows, colums;
	while(scanf("%d %d", &rows, &colums) != EOF){
		vector<vii> AdjList(colums);

		for (int i = 0; i < rows; ++i)
		{
			vi idList;
			int num_edges;
			scanf("%d", &num_edges);
			for (int j = 0; j < num_edges; ++j)
			{
				int id;
				scanf("%d", &id);
				idList.push_back(id);
			}
			for (int j = 0; j < num_edges; ++j)
			{
				int weight;
				scanf("%d", &weight);
				AdjList[ idList[ j ] - 1 ].push_back( ii( i, weight));
			}
		}

		printf("%d %d\n", colums, rows);
		for (int i = 0; i < colums; ++i)
		{
			printf("%d", (int) AdjList[i].size());
			for (int j = 0; j < (int)AdjList[i].size(); ++j)
			{
				printf(" %d", AdjList[i][j].first + 1);
			}
			printf("\n");

			for (int j = 0; j < (int)AdjList[i].size(); ++j)
			{	
				if(j)	printf(" ");
				printf("%d", AdjList[i][j].second);
			}
			printf("\n");
		}
	}

	return 0;
}