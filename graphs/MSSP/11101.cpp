#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define row second.first
#define col second.second
#define dist first 

const int INF = 1e9;
const int MAXN = 2000 + 10;
const int dr[] = {0,1,0,-1};
const int dc[] = {1,0,-1,0};

int main(){
    bool visited[MAXN][MAXN];
    bool mall[MAXN][MAXN];
    int n;
    while(scanf("%d", &n), n){
        memset(visited, 0, sizeof visited);
        memset(mall, 0, sizeof mall);

        queue< pair<int,ii> > q;
        while(n--){
            int r, c;
            scanf("%d %d", &r, &c);
            visited[r][c] = 1;
            q.push(make_pair(0, ii(r, c)));
        }

        scanf("%d", &n);
        while(n--){
            int r, c;
            scanf("%d %d", &r, &c);
            mall[r][c] = 1;
        }

        bool found = false;
        while(!found){
            auto front = q.front();
            q.pop();
            int r = front.row, c = front.col, d = front.dist;
            for(int k = 0; k < 4; k++){
                int nr = r + dr[k], nc = c + dc[k], nd = d + 1;
                if(nr < 0 || nr > 2000 || nc < 0 || nc > 2000 || visited[nr][nc])
                    continue;
                visited[nr][nc] = 1;
                if(mall[nr][nc]){
                    printf("%d\n", nd);
                    found = true;
                    break;
                }
                q.push(make_pair(nd, ii(nr, nc)));
            }
        }
    }
}