#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

const int INF = 1e9;
const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

int mf, f, s, t;
vi par;
int res[2000][2000];

void augment(int v, int minEdge){
    if(v == s){
        f = minEdge;
        return;
    }
    else if(par[v] != -1){
        augment(par[v], min(minEdge, res[par[v]][v]));
        res[par[v]][v] -= f;
        res[v][par[v]] += f;
    }
}

int main(){
    s = 0;
    int x, y, p;
    char grid[35][35];
    int id[35][35];
    while(scanf("%d %d %d", &x, &y, &p) != EOF){
        memset(res, 0, sizeof res);
        memset(id, 0, sizeof id);

        for(int i = 0; i < x; i++) // lendo o grid
            scanf("%s", grid[i]);

        int cel = 0; // atribuindo indices para as celulas do grid
        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++)
                if(grid[i][j] == '~')
                    id[i][j] = 0;
                else
                    id[i][j] = ++cel;

        int v = cel * 2 + 2; // numero de vertices = 2 * numero de celulas + source + sink

        t = v - 1;
        vector<vi> AdjList(v, vi());

        for(int i = 0; i < x; i++)
            for(int j = 0; j < y; j++){
                int u1 = id[i][j];
                int u2 = u1 + cel;
                if(u1 == 0) // agua
                    continue;
                
                AdjList[u1].push_back(u2);
                AdjList[u2].push_back(u1);

                if(grid[i][j] == '*'){
                    AdjList[s].push_back(u1);
                    AdjList[u1].push_back(s);
                    res[s][u1] = 1;
                    res[u1][u2] = 1;
                }
                else if(grid[i][j] == '.'){
                    res[u1][u2] = 1;
                }
                else
                    res[u1][u2] = INF;

                if(grid[i][j] == '#'){
                    AdjList[u2].push_back(t);
                    AdjList[t].push_back(u2);
                    res[u2][t] = p;
                }

                for(int k = 0; k < 4; k++){
                    int r = i + dr[k], c = j + dc[k];
                    if(r < 0 || r >= x || j < 0 || j >= y || grid[r][c] == '~')
                        continue;
                    int v1 = id[r][c];
                    int v2 = v1 + cel;
                    AdjList[u2].push_back(v1);
                    AdjList[v1].push_back(u2);
                    res[u2][v1] = INF;
                }
            }

        mf = 0;
        bitset<2000> bs;
        while(1){
            bs.reset();
            bs.set(s);
            par.assign(v, -1);
            queue<int> q;
            q.push(s);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == t)
                    break;
                for(int i = 0; i < (int) AdjList[u].size(); i++){
                    int w = AdjList[u][i];
                    if(bs[w] == 0 && res[u][w] > 0){
                        bs[w] = 1;
                        q.push(w);
                        par[w] = u;
                    }
                }
            }
            f = 0;
            augment(t, INF);
            if(f == 0)
                break;
            mf += f;
        }

        printf("%d\n", mf);
    }
}