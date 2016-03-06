#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;

int main(){
    int m;
    while(scanf("%d", &m), m){
        string start, finish;
        cin >> start >> finish;

        vector< pair<string, string> > lingua(m);
        vector< string > palavra(m);
        for(int i = 0; i < m; i++)
            cin >> lingua[i].first >> lingua[i].second >> palavra[i];
        
        vector< vi > AdjList(m, vi());
        for(int i = 0; i < m; i++){
            for(int j = i + 1; j < m; j++){
                if(lingua[i].first == lingua[j]. first || lingua[i].first == lingua[j].second ||
                    lingua[i].second == lingua[j].first || lingua[i].second == lingua[j].second){
                    if(palavra[i][0] != palavra[j][0]){
                        AdjList[i].push_back(j);
                        AdjList[j].push_back(i);
                    }
                }
            }
        }

        vi dist(m, INF);
        priority_queue< ii, vii, greater<ii> > pq;
        for(int i = 0; i < m; i++){
            if(lingua[i].first == start || lingua[i].second == start){
                dist[i] = palavra[i].length();
                pq.push(ii(dist[i], i));
            }
        }
        while(!pq.empty()){
            ii front = pq.top();
            pq.pop();
            int d = front.first, u = front.second;
            if(d > dist[u])
                continue;
            for(int i = 0; i < sz(AdjList[u]); i++){
                int v = AdjList[u][i];
                if(d + palavra[v].length() < dist[v]){
                    dist[v] = d + palavra[v].length();
                    pq.push(ii(dist[v], v));
                }
            }
        }

        int ans = INF;
        for(int i = 0; i < m; i++){
            if(lingua[i].first == finish || lingua[i].second == finish){
                ans = min(ans, dist[i]);
            }
        }

        if(ans == INF)
            printf("impossivel\n");
        else
            printf("%d\n", ans);
    }
}