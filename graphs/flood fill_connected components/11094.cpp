#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20 + 5;
const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};

char grid[MAXN][MAXN];
int R, C;

int floodfill(int i, int j, char c){
    if(i < 0 || i >= R)
        return 0;
    if(grid[i][j] == c)
        return 0;
    grid[i][j] = c;
    int ans = 1;
    for(int k = 0; k < 4; k++)
        ans += floodfill(i + dr[k], (j + dc[k] + C) % C, c);
    return ans;
}

int main(){
    while(scanf("%d %d", &R, &C) != EOF){
        for(int i = 0; i < R; i++)
            scanf("%s", grid[i]);

        int x, y;
        scanf("%d %d", &x, &y);

        char land = grid[x][y];
        char water = 0;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(grid[i][j] != land)
                    water = grid[i][j];
        floodfill(x, y, water);

        int ans = 0;
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(grid[i][j] == land)
                    ans = max(ans, floodfill(i, j, water));
        cout << ans << endl;
    }
}