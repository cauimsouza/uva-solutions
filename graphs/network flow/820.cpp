#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;
const int MAXV = 100 + 5;
const double EPS = 1e-9;

vi p;
vector<vi> AdjList;
bitset<MAXV> bs;
int res[MAXV][MAXV];
int mf, f, s, t;

void augment(int u, int minEdge){
    if(u == s){
        f = minEdge;
        return;
    }
    else if(p[u] != -1){
        augment(p[u], min(minEdge, res[p[u]][u]));
        res[p[u]][u] -= f;
        res[u][p[u]] += f;
    }
}

int main(){
    int v, k = 1;
    while(scanf("%d", &v),v){
        AdjList.assign(v, vi());
        memset(res, 0, sizeof res);
        int e;
        scanf("%d %d %d", &s, &t, &e);
        s--;
        t--;

        while(e--){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            res[a-1][b-1] += c;
            res[b-1][a-1] += c;
            AdjList[a-1].push_back(b-1);
            AdjList[b-1].push_back(a-1);
        }

        mf = 0;
        
        while(1){
            p.assign(v, -1);
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
                    int w = AdjList[u][i];
                    if(res[u][w] > 0 && !bs.test(w))
                        bs.set(w), q.push(w), p[w] = u;
                }
            }
            f = 0;
            augment(t, INF);
            if(f == 0)
                break;
            mf += f;
        }
        printf("Network %d\n", k++);
        printf("The bandwidth is %d.\n\n", mf);
    }
}
