#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
typedef vector<int> vi;

int main(){
    vector<vi> AdjList;
    vi color;
    int t;

    cin >> t;
    while(t--){
        int v, e;
        scanf("%d %d", &v, &e);
        AdjList.assign(v, vi());
        color.assign(v, INF);
        
        while(e--){
            int a, b;
            scanf("%d %d", &a, &b);
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }

        int cont = 0;
        bool isBipartite = true;
        for(int i = 0; i < v && isBipartite; i++){
            if(color[i] == INF){
                int white = 1;
                int black = 0;
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
                            if(color[w] == 0)
                                white++;
                            else
                                black++;
                            q.push(w);
                        }
                        else if(color[w] == color[u]){
                            isBipartite = false;
                            break;
                        }
                    }
                }
                if(black == 0)
                    cont += 1;
                else
                    cont += min(white, black);
            }
        }
        

        if(isBipartite)
            printf("%d\n", cont);
        else
            printf("-1\n");
    }
}