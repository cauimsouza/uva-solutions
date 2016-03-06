#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;

int main(){
    int v;
    scanf("%d", &v);

    vector<vi> AdjList(v, vi());
    for(int i = 0; i < v; i++){
        int e;
        scanf("%d", &e);
        while(e--){
            int v;
            scanf("%d", &v);
            AdjList[i].push_back(v);
        }
    }

    int query;
    scanf("%d", &query);
    while(query--){
        int s;
        scanf("%d", &s);

        int maxboom = 0, boomday, Counter = 0;
        int layer = -1;
        queue<int> q;
        q.push(s);
        vi dist(v, INF);
        dist[s] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(dist[u] != layer){
                layer++;
                if(Counter > maxboom){
                    maxboom = Counter;
                    boomday = layer;
                }
                Counter = 0;
            }
            for(int i = 0; i < sz(AdjList[u]); i++){
                int v = AdjList[u][i];
                if(dist[v] == INF){
                    Counter++;
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        if(Counter > maxboom){
            maxboom = Counter;
            boomday = layer + 1;
        }
        if(maxboom == 0)
            printf("0\n");
        else
            printf("%d %d\n", maxboom, boomday);
    }
}