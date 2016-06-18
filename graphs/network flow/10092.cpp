#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1100;
const int INF = 1000;

int res[MAXN][MAXN];
vector<int> p;
int mf, f, s, t;

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
    s = 0;
    t = MAXN - 1;
    vector< vector<int> > adjList;
    int nk, np;
    while(scanf("%d %d", &nk, &np), nk){
        memset(res, 0, sizeof res);
        adjList.assign(MAXN, vector<int>());
        int soma = 0;
        for(int i = 1; i <= nk; i++){
            int cap;
            scanf("%d", &cap);
            soma += cap;
            adjList[i].push_back(t);
            adjList[t].push_back(i);
            res[i][t] = cap;
        }
        for(int i = 1; i <= np; i++){
            adjList[s].push_back(nk + i);
            adjList[nk + i].push_back(s);
            res[s][nk + i] = 1;
            int num;
            scanf("%d", &num);
            while(num--){
                int cat;
                scanf("%d", &cat);
                adjList[nk + i].push_back(cat);
                adjList[cat].push_back(nk + i);
                res[nk + i][cat] = INF;
            }
        }

        mf = 0;
        bitset<MAXN> bs;
        while(1){
            bs.reset();
            bs.set(s);
            p.assign(MAXN, -1);
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == t)
                    break;
                for(int i = 0; i < (int) adjList[u].size(); i++){
                    int v = adjList[u][i];
                    if( bs[v] == 0 && res[u][v] > 0){
                        bs[v] = 1;
                        q.push(v);
                        p[v] = u;
                    }
                }
            }
            f = 0;
            augment(t, INF);
            if(f == 0)
                break;
            mf += f;
        }

        if(soma > mf)
            printf("0\n");
        else{
            printf("1\n");
            for(int i = 1; i <= nk; i++){
                bool first = true;
                for(int j = 1; j <= np; j++){
                    if(res[i][nk + j] > 0)
                        if(first){
                            first = false;
                            printf("%d", j);
                        }
                        else
                            printf(" %d", j);
                }
                printf("\n");
            }
        }
    }
}