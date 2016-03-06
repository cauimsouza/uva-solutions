#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;
const int MAXN = 1000 + 10;
const int dr[] = {0,1,0,-1};
const int dc[] = {1,0,-1,0};

int main(){
    int R, C;
    bool grid[MAXN][MAXN];
    bool visited[MAXN][MAXN];
    while(scanf("%d %d", &R, &C), R){
        memset(grid, 0, sizeof grid);
        memset(visited, 0, sizeof visited);

        int rows;
        scanf("%d", &rows);
        while(rows--){
            int id_row, num_bombs;
            scanf("%d %d", &id_row, &num_bombs);
            while(num_bombs--){
                int id_col;
                scanf("%d", &id_col);
                grid[id_row][id_col] = 1;
            }
        }

        int ini_row, ini_col, fim_row, fim_col;
        scanf("%d %d %d %d", &ini_row, &ini_col, &fim_row, &fim_col);
        queue< pair<int,ii> > q;
        q.push(make_pair(0,ii(ini_row, ini_col)));
        visited[ini_row][ini_col] = 1;
        bool found = false;
        while(!q.empty() && !found){
            auto front = q.front();
            q.pop();
            int r = front.second.first, c = front.second.second, dist = front.first;
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k], nc = c + dc[k], ndist = dist + 1;
                if(nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] || visited[nr][nc])
                    continue;
                visited[nr][nc] = 1;
                q.push(make_pair(ndist, ii(nr, nc)));
                if(nr == fim_row && nc == fim_col){
                    printf("%d\n", ndist);
                    found = true;
                    break;
                }
            }
        }
    }
}