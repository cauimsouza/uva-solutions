#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;

int main(){
    vector<vii> AdjList;
    int tc;
    cin >> tc;
    while(tc--){
        int v, e;
        scanf("%d %d", &v, &e);
        AdjList.assign(v, vii());
        for(int i = 0; i < e; i++){
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            AdjList[a].push_back(ii(b, w));
        }

        vi dist(v, INF);
        dist[0] = 0;
        for(int i = 0; i < v - 1; i++)
            for(int u = 0; u < v; u++)
                for(int j = 0; j < sz(AdjList[u]); j++){
                    ii w = AdjList[u][j];
                    if(dist[w.first] > dist[u] + w.second)
                        dist[w.first] = dist[u] + w.second;
                }

        bool hasNegativeCycle = false;
        for(int u = 0; !hasNegativeCycle && u < v; u++)
            for(int j = 0; j < sz(AdjList[u]); j++){
                ii w = AdjList[u][j];
                if(dist[w.first] > dist[u] + w.second){
                    hasNegativeCycle = true;
                    break;
                }
            }

        if(hasNegativeCycle)
            printf("possible\n");
        else
            printf("not possible\n");
    }
}