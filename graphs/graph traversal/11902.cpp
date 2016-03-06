#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;

int AdjMatrix[MAXN][MAXN], dominates[MAXN][MAXN];
int reachableFromStart[MAXN], reachable[MAXN];
int dfs_num[MAXN]; 
int v;

void dfs(int u){
    reachableFromStart[u] = 1;
    for(int i = 0; i < v; i++)
        if(AdjMatrix[u][i] && !reachableFromStart[i])
            dfs(i);
}

void dfs(int u, int removed){
    if(u == removed)
        return;
    reachable[u] = 1;
    for(int i = 0; i < v; i++)
        if(AdjMatrix[u][i] && !reachable[i])
            dfs(i, removed);
}

int main(){
   int tc, k = 1;
   scanf("%d", &tc);
   while(tc--){
        scanf("%d", &v);
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                scanf("%d", &AdjMatrix[i][j]);

        memset(reachableFromStart, 0, sizeof reachableFromStart);
        dfs(0);

        memset(dominates, 0, sizeof dominates);
        for(int i = 0; i < v; i++){
            memset(reachable, 0, sizeof reachable);
            dfs(0, i);
            for(int j = 0; j < v; j++)
                if(reachableFromStart[j] && !reachable[j])
                    dominates[i][j] = 1;
        }

        int minus = 2 * v - 1;
        printf("Case %d:\n+", k++);
        for(int i = 0; i < minus; i++)
            printf("-");
        printf("+\n");
        for(int i = 0; i < v; i++){
            printf("|");
            for(int j = 0; j < v; j++){
                if(dominates[i][j])
                    printf("Y|");
                else
                    printf("N|");
            }
            printf("\n+");
            for(int i = 0; i < minus; i++)
                printf("-");
            printf("+\n");
        }
   }
}