#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;
const int dr[] = {0,0,1,-1};
const int dc[] = {1,-1,0,0};

int main(){
    int TC;
    scanf("%d", &TC);
    while(TC--){
        int v, s, tlim, e;
        scanf("%d %d %d %d", &v, &s, &tlim, &e);
        s--;
        vector<vii> AdjList(v, vii());

        for (int i = 0; i < e; ++i)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            AdjList[v-1].push_back(ii(u-1, w));
        }

        vi dist(v, INF);
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, s));
        dist[s] = 0;
        while(!pq.empty()){
            ii front = pq.top();
            pq.pop();
            int u = front.second, d = front.first;
            if(dist[u] > d)
                continue;
            for(int i = 0; i < sz(AdjList[u]); i++){
                ii v = AdjList[u][i];
                if(d + v.second < dist[v.first]){
                    dist[v.first] = d + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < v; i++)
            if(dist[i] <= tlim)
                ans++;

        printf("%d\n", ans);
        if(TC)
            printf("\n");
    }
}