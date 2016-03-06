#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef vector<int> vi;

int main(){
    vector<vi> AdjList;
    vi color;
    int v;
    while(scanf("%d", &v), v){
        AdjList.assign(v, vi());
        color.assign(v, INF);
        
        int a, b;
        while(scanf("%d %d", &a, &b), (a || b)){
            AdjList[a-1].push_back(b-1);
            AdjList[b-1].push_back(a-1);
        }

        int cont = 0;
        bool isBipartite = true;
        for(int i = 0; i < v && isBipartite; i++){
            if(color[i] == INF){
                color[i] = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty() && isBipartite){
                    int u = q.front();
                    q.pop();
                    for(int j = 0; j < (int)AdjList[u].size(); j++){
                        int w = AdjList[u][j];
                        if(color[w] == INF){
                            color[w] = 1 - color[u];
                            q.push(w);
                        }
                        else if(color[w] == color[u]){
                            isBipartite = false;
                            break;
                        }
                    }
                }
            }
        }
        

        if(isBipartite)
            printf("YES\n");
        else
            printf("NO\n");
    }
}