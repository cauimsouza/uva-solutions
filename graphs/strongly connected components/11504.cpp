#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

vi dfs_num;
vi dfs_low;
vi scc;
vi sccIncDegree;
vector<vi> AdjList;
vi visited;
vi S;
int dfsCounter, sccCounter;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = ++dfsCounter;
    S.push_back(u);
    visited[u] = 1;
    for(int i = 0; i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == 0)
            tarjanSCC(v);
        if(visited[v] == 1)
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if(dfs_low[u] == dfs_num[u]){
        int v;
        do{
            v = S.back();
            S.pop_back();
            visited[v] = 0;
            scc[v] = sccCounter;
        }while(v != u);
        sccCounter++;
    }
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int v, e;
        scanf("%d %d", &v, &e);
        dfs_low.assign(v, 0);
        dfs_num.assign(v, 0);
        visited.assign(v, 0);
        AdjList.assign(v, vi());
        scc.assign(v, 0);
        sccIncDegree.assign(v, 0);
        S.clear();

        while(e--){
            int v1, v2, type;
            scanf("%d %d", &v1, &v2);
            AdjList[v1-1].push_back(v2-1);
        }

        dfsCounter = 0;
        sccCounter = 0;
        for(int i = 0; i < v; i++)
            if(dfs_num[i] == 0)
                tarjanSCC(i);

        int ans = sccCounter;
        for(int u = 0; u < v; u++)
            for(int j = 0; j < (int)AdjList[u].size(); j++){
                int w = AdjList[u][j];
                if(scc[u] != scc[w]){
                    if(sccIncDegree[scc[w]] == 0)
                        ans--;
                    sccIncDegree[scc[w]]++;
                }
            }

        printf("%d\n", ans);
    }
}