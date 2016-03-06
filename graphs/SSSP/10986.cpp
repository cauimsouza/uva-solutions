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
    int TC, k = 1;
    scanf("%d", &TC);
    while(TC--){
        int v, e, s, t;
        scanf("%d %d %d %d", &v, &e, &s, &t);

        AdjList.assign(v, vii());
        for (int i = 0; i < e; ++i)
        {
            int s1, s2, w;
            scanf("%d %d %d", &s1, &s2, &w);
            AdjList[s1].push_back(ii(s2, w));
            AdjList[s2].push_back(ii(s1, w));
        }

        vi dist(v, INF);
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0, s));
        dist[s] = 0;
        while(!pq.empty()){
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if(dist[u] > d)
                continue;
            for(int i = 0; i < sz(AdjList[u]); i++){
                ii w = AdjList[u][i];
                if(dist[w.first] > d + w.second){
                    dist[w.first] = d + w.second;
                    pq.push(ii(dist[w.first], w.first));
                } 
            } 
        }

        printf("Case #%d: ", k++);
        if(dist[t] < INF)
            printf("%d\n", dist[t]);
        else
            printf("unreachable\n");
    }
}