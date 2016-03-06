#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef vector<int> vi;

vector<vi> AdjList;
vi color;
bool isBipartite;

void dfs(int u, int clr){
    color[u] = clr;
    for(int i = 0; isBipartite && i < (int)AdjList[u].size(); i++){
        int v = AdjList[u][i];
        if(color[v] == INF)
            dfs(v, 1 - clr);
        else if(color[u] == color[v]){
            isBipartite = false;
            break;
        }
    } 
}

int main(){
    int v;
    while(scanf("%d", &v), v){
        AdjList.assign(v, vi());
        color.assign(v, INF);
        
        int l;
        scanf("%d", &l);
        while(l--){
            int a, b;
            scanf("%d %d", &a, &b);
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }

        isBipartite = true;
        for(int i = 0; i < v && isBipartite; i++){
            if(color[i] == INF){
                dfs(i, 0);
            }
        }
        

        if(isBipartite)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
}