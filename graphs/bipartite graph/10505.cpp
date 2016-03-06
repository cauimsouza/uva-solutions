#include <bits/stdc++.h>
using namespace std;

const int UNVISITED = -1;
using vi = vector<int>;

int main(){
    int tc;
    vector<vi> AdjList;
    vi color;
    cin >> tc;
    while(tc--){
        int v;
        scanf("%d", &v);
        AdjList.assign(v, vi());
        color.assign(v, UNVISITED);

        for(int i = 0; i < v; i++){
            int p;
            scanf("%d", &p);
            while(p--){
                int a;
                scanf("%d", &a);
                if(a <= v && a > 0){
                    AdjList[i].push_back(a-1);
                    AdjList[a-1].push_back(i);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < v; i++){
            if(color[i] == UNVISITED){
                bool isBipartite = true;
                color[i] = 0;
                int white = 1;
                int black = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int u = q.front();
                    q.pop();
                    for(int i = 0; i < (int) AdjList[u].size(); i++){
                        int w = AdjList[u][i];
                        if(color[w] == UNVISITED){
                            color[w] = 1 - color[u];
                            if(color[w] == 0)
                                white++;
                            else
                                black++;
                            q.push(w);
                        }
                        else if(color[w] == color[u]){
                            isBipartite = false;
                        }
                    }
                }
                ans += isBipartite ? max(white, black) : 0;
            }
        }

        printf("%d\n", ans);
    }
}