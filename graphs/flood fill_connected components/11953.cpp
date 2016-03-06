#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100 + 5;
const int dr[] = {1,-1,0,0};
const int dc[] = {0,0,1,-1};

char grid[MAXN][MAXN];
int n;

void floodfill(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= n)
        return;
    if(grid[i][j] == '.')
        return;
    grid[i][j] = '.';
    for(int k = 0; k < 4; k++)
        floodfill(i + dr[k], j + dc[k]);
}

int main(){
    int tc, k = 1;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", grid[i]);

        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 'x'){
                    ans++;
                    floodfill(i, j);
                }
        printf("Case %d: %d\n", k++, ans);
    }
}