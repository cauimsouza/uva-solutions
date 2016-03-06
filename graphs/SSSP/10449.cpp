#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;

inline int cubo(int x){
    return x * x * x;
}

vi dfs_num;
vi negInf;
vector<vi> AdjList;

void dfs(int u){
    dfs_num[u] = negInf[u] = 1;
    for(int i = 0; i < sz(AdjList[u]); i++){
        int v = AdjList[u][i];
        if(dfs_num[v] == 0)
            dfs(v);
    }
}

int main(){
    int n, k = 1;
    while(scanf("%d", &n) == 1){
        vi busy(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &busy[i]);

        int e;
        scanf("%d", &e);
        AdjList.assign(n, vi());
        while(e--){
            int a, b;
            scanf("%d %d", &a, &b);
            AdjList[a-1].push_back(b-1);
        }

        vi dist(n, INF);
        dist[0] = 0;
        for(int i = 0; i < n - 1; i++)
            for(int u = 0; u < n; u++)
                for(int j = 0; j < sz(AdjList[u]); j++){
                    int v = AdjList[u][j];
                    if(dist[u] != INF && dist[v] > dist[u] + cubo(busy[v] - busy[u])){
                        dist[v] = dist[u] + cubo(busy[v] - busy[u]);
                    }
                }

        negInf.assign(n, 0);
        dfs_num.assign(n, 0);
        for(int u = 0; u < n; u++)
            if(!dfs_num[u] && dist[u] < INF)
                for(int j = 0; j < sz(AdjList[u]); j++){
                    int v = AdjList[u][j];
                    if(dist[v] > dist[u] + cubo(busy[v] - busy[u])){
                        dfs(u);
                        break;
                    }
                }

        int q;
        scanf("%d", &q);
        printf("Set #%d\n", k++);
        while(q--){
            int dest;
            scanf("%d", &dest);
            int ans = dist[dest - 1];
            if(ans < 3 || negInf[dest - 1] || ans == INF)
                printf("?\n");
            else
                printf("%d\n", ans);
        }
    }
}