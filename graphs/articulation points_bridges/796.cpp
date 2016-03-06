#include <bits/stdc++.h>
using namespace std;

const int UNVISITED = -1;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> AdjList;
vector<ii> EdgeList;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
vi articulation_vertex;
int dfsCounter;

void dfs(int u){
    dfs_num[u] = dfs_low[u] = dfsCounter++;
    for(int i = 0; i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];

        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;

            dfs(v);

            if(dfs_low[v] > dfs_num[u])
                EdgeList.push_back(ii(min(u,v), max(u,v)));

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
    int v;
    while(scanf("%d", &v) != EOF){
        dfs_num.assign(v, UNVISITED);
        dfs_low.assign(v, 0);
        AdjList.assign(v, vi());
        dfs_parent.assign(v, -1);
        articulation_vertex.assign(v, 0);
        EdgeList.clear();

        for(int i = 0; i < v; i++){
            int v1, edges;
            scanf("%d (%d)", &v1, &edges);
            for(int j = 0; j < edges; j++){
                int v2;
                scanf("%d", &v2);
                AdjList[v1].push_back(v2);
                AdjList[v2].push_back(v1);
            }
        }

        dfsCounter = 0;
        for(int i = 0; i < v; i++)
            if(dfs_num[i] == UNVISITED)
                dfs(i);

        sort(EdgeList.begin(), EdgeList.end());
        printf("%d critical links\n", (int)EdgeList.size());
        for(int i = 0; i < (int) EdgeList.size(); i++)
            printf("%d - %d\n", EdgeList[i].first, EdgeList[i].second);
        printf("\n");
    }
}