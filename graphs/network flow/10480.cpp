#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())

const int INF = 1e9;
using vi =  vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

const int MAXN = 50 + 5;

int res[MAXN][MAXN];
int mf, f, s = 0, t = 1;
vi p;

void augment(int v, int minEdge){
    if(v == s){
        f = minEdge;
        return;
    }
    else if(p[v] != -1){
        augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f;
        res[v][p[v]] += f;
    }
}

int main(){
    int n, m;
    vector<vi> AdjList;
    while(scanf("%d %d", &n, &m), n){
        AdjList.assign(n, vi());
        memset(res, 0, sizeof res);
        while(m--){
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            res[a-1][b-1] = w;
            res[b-1][a-1] = w;
            AdjList[a-1].push_back(b-1);
            AdjList[b-1].push_back(a-1);
        }

        bitset<MAXN> bs;
        while(1){
            f = 0;
            p.assign(n, -1);
            bs.reset();
            bs.set(s);
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == t)
                    break;
                for(int i = 0; i < sz(AdjList[u]); i++){
                    int v = AdjList[u][i];
                    if(!bs[v] && res[u][v] > 0)
                        bs[v] = 1, q.push(v), p[v] = u;
                }
            }
            augment(t, INF);
            if(f == 0)
                break;
        }
        for(int u = 0; u < n; u++)
            for(int j = 0; j < sz(AdjList[u]); j++){
                int v = AdjList[u][j];
                if(u < v && (bs[u] != bs[v]))
                    printf("%d %d\n", u + 1, v + 1);
            }

        printf("\n");
    }
}