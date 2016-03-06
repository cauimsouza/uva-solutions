#include <bits/stdc++.h>
using namespace std;

const int UNVISITED = -1;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> AdjList;
vector<ii> AnsList;
vi dfs_num;
vi dfs_low;
vi dfs_parent;
int dfsCounter, root, rootChildren;

void dfs(int u){
    dfs_num[u] = dfs_low[u] = ++dfsCounter;
    int Counter = 1;
    for(int i = 0; i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];

        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            if(u == root)
                rootChildren++;

            dfs(v);

            if(dfs_low[v] >= dfs_num[u])
                Counter++;

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    if(u != root)
        AnsList.push_back(ii(u, Counter));
}

bool ordena(ii a, ii b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main(){
    int v, m;
    while(scanf("%d %d", &v, &m), v){
        dfs_num.assign(v, UNVISITED);
        dfs_low.assign(v, 0);
        AdjList.assign(v, vi());
        dfs_parent.assign(v, -1);
        AnsList.clear();

        int v1, v2;
        while(scanf("%d %d", &v1, &v2), (v1 >= 0)){
            AdjList[v1].push_back(v2);
            AdjList[v2].push_back(v1);
        }

        dfsCounter = 0;
        for(int i = 0; i < v; i++)
            if(dfs_num[i] == UNVISITED){
                root = i;
                rootChildren = 0;
                dfs(i);

                AnsList.push_back(ii(i, rootChildren));
            }

        sort(AnsList.begin(), AnsList.end(), ordena);
        for(int i = 0; i < m; i++)
            printf("%d %d\n", AnsList[i].first, AnsList[i].second);
        printf("\n");
    }
}