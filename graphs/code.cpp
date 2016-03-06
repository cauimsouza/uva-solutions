#include <bits/stdc++.h>
using namespace std;

const int UNVISITED = -1;
typedef vector<int> vi;

vector<vi> AdjList;
vi dfs_num;
vi dfs_parent;
vi dfs_low;
vi articulation_vertex;
int dfs_root, rootChildren, dfs_Counter;

void dfs(int u){
    dfs_num[u] = dfs_low[u] = dfs_Counter++;
    for(int i = 0; i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;

            dfs(v);

            if(u == dfs_root)
                rootChildren++;

            if(dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = true;

            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
    int v;
    while(scanf("%d", &v), v){
        AdjList.assign(v, vi());
        dfs_num.assign(v, UNVISITED);
        dfs_low.assign(v, 0);
        dfs_parent.assign(v, 0);
        articulation_vertex.assign(v, 0);
        
        int v1;
        scanf("%d", &v1);
        while(v1){
            int v2;
            char c;
            do{
                scanf("%d%c", &v2, &c);
                AdjList[v1-1].push_back(v2-1);
                AdjList[v2-1].push_back(v1-1);
            }while(c != '\n');
            scanf("%d", &v1);
        }

        for(int i = 0; i < v; i++)
            if(dfs_num[i] == UNVISITED){
                dfs_root = i;
                rootChildren = dfs_Counter = 0;
                dfs(i);
                articulation_vertex[i] = (rootChildren > 1);
            }
        
        int Counter = 0;
        for(int i = 0; i < v; i++)
            if(articulation_vertex[i])
                Counter++;

        printf("%d\n", Counter);
    }
}