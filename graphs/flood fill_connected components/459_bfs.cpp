#include <bits/stdc++.h>
using namespace std;

const bool VISITED = true;
const bool UNVISITED = false;

int v, CC;
bool AdjMatrix[30][30];
bool bfs_num[30];

void bfs(int u){
    bfs_num[u] = VISITED;
    queue<int> q;
    q.push(u);
    while(!q. empty()){
        int k = q.front();
        q.pop();
        for(int i = 0; i < v; i++)
            if(AdjMatrix[k][i] && bfs_num[i] == UNVISITED){
                bfs_num[i] = VISITED;
                q.push(i);
            }
    }
}

int main(){
   int tc;
   scanf("%d\n\n", &tc);
   while(tc--){
        memset(AdjMatrix, false, sizeof AdjMatrix);
        memset(bfs_num, UNVISITED, sizeof bfs_num);
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
            if(bfs_num[i] == UNVISITED){
                CC++;
                bfs(i);
            }

        printf("%d\n", CC);
        if(tc)
            printf("\n");
   }
}