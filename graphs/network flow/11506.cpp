#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

const int INF = 1e9;
const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int mf, f, s, t;
vi p;
int res[105][105];

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
    int m, w;
    vector<vi> AdjList;
    while(scanf("%d %d", &m, &w), m){
        memset(res, 0, sizeof res);
        AdjList.assign(2 * m + 10, vi());
        s = 1;
        t = m;
        AdjList[s].push_back(s + m);
        AdjList[s + m].push_back(s);
        AdjList[t].push_back(t + m);
        AdjList[t + m].push_back(t);
        res[s][s + m] = INF;
        res[t][t + m] = INF;

        for(int i = 0; i < m - 2; i++){
            int id, cost;
            scanf("%d %d", &id, &cost);
            AdjList[id].push_back(id + m);
            AdjList[id + m].push_back(id);
            res[id][id + m] = cost;
        }

        for(int i = 0; i < w; i++){
            int u, v, cost;
            scanf("%d %d %d", &u, &v, &cost);
            AdjList[u + m].push_back(v);
            AdjList[v].push_back(u + m);
            res[u + m][v] = cost;
            AdjList[v + m].push_back(u);
            AdjList[u].push_back(v + m);
            res[v + m][u] = cost;
        }

        mf = 0;
        bitset<110> bs;
        while(1){
            bs.reset();
            bs.set(s);
            p.assign(2 * m + 10, -1);
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == t + m)
                    break;
                for(int i = 0; i < (int) AdjList[u].size(); i++){
                    int v = AdjList[u][i];
                    if(res[u][v] > 0 && bs[v] == 0){
                        bs[v] = 1;
                        p[v] = u;
                        q.push(v);
                    }
                }
            }
            f = 0;
            augment(t + m, INF);
            if(f == 0)
                break;
            mf += f;
        }

        printf("%d\n", mf);
    }
}