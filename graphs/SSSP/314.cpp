#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

int main(){
    //freopen("in", "r", stdin);
    bool grid[55][55];
    bool visited[55][55][5];
    int n, m;
    while(scanf("%d %d", &n, &m), n){
        memset(grid, 0, sizeof grid);
        memset(visited, 0, sizeof visited);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                int x;
                scanf("%d", &x);
                if(x)
                    grid[i][j] = grid[i+1][j] = grid[i][j+1] = grid[i+1][j+1] = 1;
            }

        int r1, c1, r2, c2, ori;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        string ort;
        cin >> ort;
        
        if(ort == "east")
            ori = 0;
        else if(ort == "north")
            ori = 1;
        else if(ort == "west")
            ori = 2;
        else
            ori = 3;

        priority_queue< pair<ii, ii> > q; // (distance,orientation),(row,column)
        q.push(make_pair(ii(0, ori), ii(r1, c1)));
        visited[r1][c1][ori] = 1;
        bool found = false;
        while(!found && !q.empty()){
            auto front = q.top();
            q.pop();
            int r = front.second.first, c = front.second.second, d = -(front.first.first), ori = front.first.second;
            
            if(r == r2 && c == c2){
                found = true;
                printf("%d\n", d);
                break;
            }

            for(int k = 1; k <= 3; k++){
                int nr, nc, nd, nori = ori;
                if(ori == 0){
                    nr = r;
                    nc = c + k;
                    nd = d + 1;
                }
                else if(ori == 1){
                    nr = r - k;
                    nc = c;
                    nd = d + 1;
                }
                else if(ori == 2){
                    nr = r;
                    nc = c - k;
                    nd = d + 1;
                }
                else if(ori == 3){
                    nr = r + k;
                    nc = c;
                    nd = d + 1;
                }
                if(nr < 1 || nr >= n || nc < 1 || nc >= m || visited[nr][nc][ori])
                        continue;
                if(grid[nr][nc])
                    break;
                visited[nr][nc][nori] = 1;
                q.push(make_pair(ii(-nd, nori), ii(nr, nc)));
            }

            if(!visited[r][c][(ori+1)%4]){
                visited[r][c][(ori+1)%4] = 1;
                q.push(make_pair(ii(-d-1,(ori+1+4)%4),ii(r,c)));
            }
            if(!visited[r][c][(ori-1)%4]){
                visited[r][c][(ori-1)%4] = 1;
                q.push(make_pair(ii(-d-1,(ori-1+4)%4),ii(r,c)));
            }
        }

        if(!found)
            printf("-1\n");
    }
}