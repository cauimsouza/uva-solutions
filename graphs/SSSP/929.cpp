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
    int grid[1005][1005];
    int dist[1005][1005];
    int TC;
    scanf("%d", &TC);
    while(TC--){
        int n, m;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                dist[i][j] = INF;
                scanf("%d", &grid[i][j]);
            }

        dist[0][0] = grid[0][0];
        priority_queue< pair<int,ii>, vector< pair<int, ii> >, greater< pair<int, ii> > > pq;
        pq.push(make_pair(grid[0][0], ii(0,0)));
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();
            int d = front.first, r = front.second.first, c = front.second.second;
            if(dist[r][c] > d)
                continue;
            
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k], nc = c + dc[k];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;
                if(dist[r+dr[k]][c+dc[k]] > d + grid[r+dr[k]][c+dc[k]]){
                    dist[r+dr[k]][c+dc[k]] = d + grid[r+dr[k]][c+dc[k]];
                    pq.push(make_pair(dist[r+dr[k]][c+dc[k]], ii(r + dr[k], c + dc[k])));
                }
            }
        }

        printf("%d\n", dist[n-1][m-1]);
    }
}