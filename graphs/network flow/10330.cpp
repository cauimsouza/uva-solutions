#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())

const int INF = 1e9;
using vi =  vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

const int MAXN = 200 + 10;

int res[MAXN][MAXN];
vector<vi> AdjList;
vi p;
int mf, f, s = 0, t;

void setVert(int);
void setEdges(int);
void setBeginEnd(int);
void augment(int, int);

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        AdjList.assign(MAXN, vi());
        memset(res, 0, sizeof res);
        t = MAXN - 1;
        
        setVert(n);

        setEdges(n);
        
        setBeginEnd(n);

        bitset<MAXN> bs;
        mf = 0;
        while(1){
            bs.reset();
            bs.set(s);
            p.assign(MAXN, -1);
            f = 0;
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == t)
                    break;
                for(int i = 0; i < sz(AdjList[u]); i++){
                    int v = AdjList[u][i];
                    if(!bs[v] && res[u][v] > 0){
                        bs.set(v);
                        q.push(v);
                        p[v] = u;
                    }
                }
            }
            augment(t, INF);
            if(f == 0)
                break;
            mf += f;
        }
        printf("%d\n", mf);
    }
}

void setVert(int n){
    for(int i = 1; i <= n; i++){
        int w;
        scanf("%d", &w);
        res[i][i + n] = w;
        AdjList[i].push_back(i + n);
        AdjList[i + n].push_back(i);
    }
}

void setEdges(int n){
    int edges;
    scanf("%d", &edges);
    while(edges--){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        res[a + n][b] += w;
        AdjList[a + n].push_back(b);
        AdjList[b].push_back(a + n);
    }
}

void setBeginEnd(int n){
    int b, d;
    scanf("%d %d", &b, &d);
    while(b--){
        int v;
        scanf("%d", &v);
        AdjList[0].push_back(v);
        AdjList[v].push_back(0);
        res[0][v] = INF;
    }
    while(d--){
        int v;
        scanf("%d", &v);
        res[v + n][t] = INF;
        AdjList[v + n].push_back(t);
        AdjList[t].push_back(v + n);
    }
}

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