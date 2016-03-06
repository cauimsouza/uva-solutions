#include <bits/stdc++.h>
using namespace std;

int R = 0, C = 0;
char grid[110][110];
int dr[] = {1,0,0,-1,1,1,-1,-1};
int dc[] = {0,1,-1,0,1,-1,1,-1};

int floodfill(int r, int c, char c1, char c2){
    if(r < 0 || r >= R || c < 0 || c >= C)
        return 0;
    if(grid[r][c] != c1)
        return 0;
    grid[r][c] = c2;
    int ans = 1;
    for(int i = 0; i < 8; i++)
        ans += floodfill(r + dr[i], c + dc[i], c1, c2);
    return ans;
}

void solve(){
    scanf("%s", grid[R++]);
    while(isalpha(grid[R-1][0])){
        scanf("%s", grid[R++]);
    }
    R--;
    C = strlen(grid[0]);

    int r = 0, c;
    for(int i = 0; i < strlen(grid[R]); i++){
        r = r * 10 + grid[R][i] - '0';
    }
    scanf("%d", &c);

    while(true){
        char c1 = grid[r-1][c-1];
        printf("%d\n", floodfill(r - 1, c - 1, c1, c1 + 1));

        char ch;
        getchar();
        ch = getchar();
        if(ch == '\n' || ch == EOF)
            break;
        r = 0;
        while(isdigit(ch)){
            r = 10 * r + ch - '0';
            ch = getchar();
        }
        scanf("%d", &c);
    }
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        R = C = 0;
        solve();
        if(tc)
            printf("\n");
    }
}