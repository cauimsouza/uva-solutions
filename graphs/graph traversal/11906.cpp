#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

int main(){
    int t, k = 1;
    int r, c, m, n;
    bool visited[105][105];
    bool water[105][105];
    cin >> t;
    while(t--){
        int w;
        scanf("%d %d %d %d %d", &r, &c, &m, &n, &w);
        memset(visited, false, sizeof visited);
        memset(water, false, sizeof water);
        while(w--){
            int x, y;
            scanf("%d %d", &x, &y);
            water[x][y] = true;
        }

        int even, odd;
        even = odd = 0;
        int v1[8] = {m,m,-m,-m,n,n,-n,-n};
        int v2[8]= {n,-n,n,-n,m,-m,m,-m};
        queue<pair<int,int> > q;
        set<ii> cnjt;
        q.push(ii(0,0));
        visited[0][0] = true;
        while(!q.empty()){
            ii v = q.front();
            q.pop();
            int cont = 0;
            cnjt.clear();

            for(int k = 0; k < 8; k++){
                if(v.first  + v1[k] < r && v.second + v2[k] < c && v.first + v1[k] >= 0 && v.second + v2[k] >= 0 && !water[v.first + v1[k]][v.second + v2[k]]){
                    ii newPar = ii(v.first  + v1[k], v.second + v2[k]);
                    if(cnjt.find(newPar) == cnjt.end()){
                        cnjt.insert(newPar);
                        cont++;
                        if(!visited[v.first + v1[k]][v.second + v2[k]]){
                            q.push(ii(v.first + v1[k], v.second + v2[k]));
                            visited[v.first + v1[k]][v.second + v2[k]] = true;
                        }
                    }
                }
            }
            
            if(cont%2)
                odd++;
            else
                even++;
        }

        printf("Case %d: %d %d\n", k++, even, odd);
    }
}