#include <bits/stdc++.h>
using namespace std;

const bool VISITED = true;
const bool UNVISITED = false;

int v, CC;
bool AdjMatrix[30][30];
bool dfs_num[30];

void dfs(int u){
    dfs_num[u] = VISITED;
    for(int i = 0; i < v; i++)
        if(AdjMatrix[u][i] && dfs_num[i] == UNVISITED)
            dfs(i);
}

int main(){
   int tc;
   scanf("%d\n\n", &tc);
   while(tc--){
        memset(AdjMatrix, false, sizeof AdjMatrix);
        memset(dfs_num, UNVISITED, sizeof dfs_num);
        char c;
        scanf("%c", &c);
        v = c - 'A' + 1;

        c = getchar();
        c = getchar();
        while(c != '\n' && c != EOF){
            char v1;
            scanf("%c", &v1);
            AdjMatrix[v1 - 'A'][c - 'A'] = AdjMatrix[c - 'A'][v1 - 'A'] = true; 
            c = getchar();
            c = getchar();
        }

        CC = 0;
        for(int i = 0; i < v; i++)
            if(dfs_num[i] == UNVISITED){
                CC++;
                dfs(i);
            }

        printf("%d\n", CC);
        if(tc)
            printf("\n");
   }
}