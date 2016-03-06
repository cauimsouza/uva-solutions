#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;

int main(){
    int n, k;
    int vel[10];
    vector<vi> Andares;
    while(scanf("%d %d", &n, &k) != EOF){
        Andares.assign(n, vi());
        for(int i = 0; i < n; i++)
            scanf("%d", &vel[i]);

        for(int i = 0; i < n; i++){
            char c;
            do{
                int x;
                scanf("%d", &x);
                Andares[i].push_back(x);
            }while((c = getchar()) != '\n' && c != EOF);
        }

        vi dist(105, INF);
        dist[0] = -60;
        priority_queue<ii, vii, greater<ii> > pq;
        pq.push(ii(-60, 0));
        while(!pq.empty()){
            ii front = pq.top();
            pq.pop();
            int andar = front.second, tempo = front.first;
            if(dist[andar] > tempo)
                continue;
            for(int elv = 0; elv < n; elv++){
                if(!binary_search(all(Andares[elv]), andar))
                    continue;
                for(int i = 0; i < sz(Andares[elv]); i++){
                    int u = Andares[elv][i];
                    if(u == andar)
                        continue;
                    int relax = tempo + 60 + vel[elv] * abs(u - andar);
                    if(dist[u] > relax){
                        dist[u] = relax;
                        pq.push(ii(relax, u));
                    }
                }
            }
        }
        dist[0] = 0;

        if(dist[k] == INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", dist[k]);
    }
}