#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi dfs_num;
vi dfs_low;
vector<vi> AdjList;
vi visited;
vi S;
int dfsCounter;
bool isConnected;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = ++dfsCounter;
    visited[u] = 1;
    S.push_back(u);
    for(int i = 0; i < AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == 0)
            tarjanSCC(v);
        if(visited[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]){
        int v = S.back();
        S.pop_back();
        while(v != u){
            v = S.back();
            S.pop_back();
        }
        if(!S.empty())
            isConnected = false;
    }
}

int main(){
    int v, e;
    while(scanf("%d %d", &v, &e), v){
        dfs_low.assign(v, 0);
        dfs_num.assign(v, 0);
        visited.assign(v, 0);
        AdjList.assign(v, vi());
        S.clear();

        while(e--){
            int v1, v2, type;
            scanf("%d %d %d", &v1, &v2, &type);
            AdjList[v1-1].push_back(v2-1);
            if(type == 2)
                AdjList[v2-1].push_back(v1-1);
        }

        dfsCounter = 0;
        isConnected = true;
        tarjanSCC(0);
        for(int i = 0; isConnected && i < v; i++)
            if(dfs_num[i] == 0){
                isConnected = false;
                break;
            }

        printf("%d\n", isConnected);
    }
}