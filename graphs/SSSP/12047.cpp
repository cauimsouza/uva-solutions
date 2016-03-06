#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;

int main(){
    vector<vii> AdjList, AdjListInv;
    int tc;
    cin >> tc;
    while(tc--){
        int n, m, s, t, p;
        scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
        AdjList.assign(n, vii());
        AdjListInv.assign(n, vii());
        for(int i = 0; i < m; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            AdjList[u-1].push_back(ii(v-1, w));
            AdjListInv[v-1].push_back(ii(u-1, w));
        }

        vi dist(n, INF);
        
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, s - 1));
        dist[s-1] = 0;
        while(!pq.empty()){
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if(dist[u] > d)
                continue;
            for(int i = 0; i < sz(AdjList[u]); i++){
                ii v = AdjList[u][i];
                if(dist[v.first] > d + v.second){
                    dist[v.first] = d + v.second;
                    pq.push(ii(dist[v.first], v.first));
                }
            }
        }

        vi distInv(n, INF);
        pq.push(ii(0, t - 1));
        distInv[t-1] = 0;
        while(!pq.empty()){
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if(distInv[u] > d)
                continue;
            for(int i = 0; i < sz(AdjListInv[u]); i++){
                ii v = AdjListInv[u][i];
                if(distInv[v.first] > d + v.second){
                    distInv[v.first] = d + v.second;
                    pq.push(ii(distInv[v.first], v.first));
                }
            }
        }

        int ans = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < sz(AdjList[i]); j++){
                ii v = AdjList[i][j];
                if(dist[i] + distInv[v.first] + v.second <= p)
                    ans = max(ans, v.second);
            }
        }

        printf("%d\n", ans);
    }
}