#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;

vector<vi> AdjList;
vi dfs_num;

void dfs(int u){
    dfs_num[u] = 1;
    for(int i = 0; i < sz(AdjList[u]); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == 0)
            dfs(v);
    }
}

int main(){
    
    vi energy;
    int v;
    while(scanf("%d", &v), (v != -1)){
        AdjList.assign(v, vi());
        energy.resize(v);

        for(int i = 0; i < v; i++){
            int e;
            scanf("%d %d", &energy[i], &e);
            for(int j = 0; j < e; j++){
                int x;
                scanf("%d", &x);
                AdjList[i].push_back(x-1);
            }
        }

        vi dist(v, -INF);
        dist[0] = 100;
        for(int i = 0; i < v - 1; i++)
            for(int u = 0; u < v; u++)
                if(dist[u] != -INF)
                    for(int j = 0; j < sz(AdjList[u]); j++){
                        int w = AdjList[u][j];
                        if(dist[w] < dist[u] + energy[w] && dist[u] + energy[w] > 0)
                            dist[w] = dist[u] + energy[w];
                    }

        dfs_num.assign(v, 0);
        for(int i = 0; i < v; i++)
            if(dist[i] != INF && dfs_num[i] == 0)
                for(int j = 0; j < sz(AdjList[i]); j++){
                    int u = AdjList[i][j];
                    if(dist[u] > 0 && dist[i] + energy[u] > dist[u])
                        dfs(i);
                }
        

        if(dist[v-1] > 0 || dfs_num[v-1] == 1)
            printf("winnable\n");
        else
            printf("hopeless\n");
    }
}