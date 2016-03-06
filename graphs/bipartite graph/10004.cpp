#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

typedef vector<int> vi;

int main(){
    vector<vi> AdjList;
    vi color;
    int n;
    while(scanf("%d", &n), n){
        AdjList.assign(n, vi());
        color.assign(n, INF);
        int l;
        scanf("%d", &l);
        while(l--){
            int a, b;
            scanf("%d %d", &a, &b);
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }

        queue<int> q;
        q.push(0);
        color[0] = 0;
        bool isBipartite = true;
        while(!q.empty() && isBipartite){
            int u = q.front();
            q.pop();
            for(int i = 0; i < (int)AdjList[u].size(); i++){
                int v = AdjList[u][i];
                if(color[v] == INF){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]){
                    isBipartite = false;
                    break;
                }
            }
        }

        if(isBipartite)
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
}