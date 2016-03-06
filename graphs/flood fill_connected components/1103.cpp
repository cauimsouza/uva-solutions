#include <bits/stdc++.h>
using namespace std;

const int MAXH = 300;
const int MAXW = 300;
const char dic[][4] = {
    {'0','0','0','0'},
    {'0','0','0','1'},
    {'0','0','1','0'},
    {'0','0','1','1'},
    {'0','1','0','0'},
    {'0','1','0','1'},
    {'0','1','1','0'},
    {'0','1','1','1'},
    {'1','0','0','0'},
    {'1','0','0','1'},
    {'1','0','1','0'},
    {'1','0','1','1'},
    {'1','1','0','0'},
    {'1','1','0','1'},
    {'1','1','1','0'},
    {'1','1','1','1'}
};
const int dr[] = {1,0,-1,0,1,1,-1,-1};
const int dc[] = {0,1,0,-1,1,-1,1,-1};
inline int charToInt(char c){
    if(isdigit(c))
        return c - '0';
    return 10 + c - 'a';
}

char grid[MAXH][MAXW];
bool visited[MAXH][MAXW];
int h, w;

void color(int i, int j){
    if(i < 0 || i > h + 1 || j < 0 || j > 4 * w + 1)
        return;
    if(grid[i][j] == '1' || grid[i][j] == '2')
        return;
    grid[i][j] = '2';
    for(int k = 0; k < 4; k++)
        color(i + dr[k], j + dc[k]);
}

int floodfill(int i, int j){
    if(i < 0 || i > h + 1 || j < 0 || j > 4 * w + 1)
        return 0;
    if(visited[i][j] || grid[i][j] == '2') // a black cell already visited or an external white cell
        return 0;
    if(grid[i][j] == '1'){// a black cell not visited yet
        visited[i][j] = true;
        int ans = 0;
        for(int k = 0; k < 4; k++)
            ans += floodfill(i + dr[k], j + dc[k]);
        return ans;
    }
    color(i, j);// a white cell not visited yet
    return 1;
}

void solve(){
    vector<char> out; 
    memset(visited, false, sizeof visited);
    color(0,0);
    /*for(int i = 0; i <= h + 1; i++){
        for(int j = 0; j <= 4 * w + 1; j++)
            printf("%c", grid[i][j]);
        printf("\n");
    }*/
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= 4 * w; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                int cont = floodfill(i, j);
                if(cont == 0)
                    out.push_back('W');
                else if(cont == 1)
                    out.push_back('A');
                else if(cont == 2)
                    out.push_back('K');
                else if(cont == 3)
                    out.push_back('J');
                else if(cont == 4)
                    out.push_back('S');
                else
                    out.push_back('D');
            }
        }
    }
    sort(out.begin(), out.end());
    for(int i = 0; i < (int)out.size(); i++)
        printf("%c", out[i]);
    printf("\n"); 
}

int main(){
    int cont = 1;
    while(scanf("%d %d", &h, &w) != EOF){
        if(h == 0)
            break;
        memset(grid, '0', sizeof grid);
        char c;
        for(int i = 0 ; i < h; i++){
            for(int j = 0; j < w; j++){
                scanf(" %c", &c);
                strcpy(&grid[i+1][4 * j + 1], dic[charToInt(c)]);
            }
            grid[i + 1][4 * w + 1] = '0';
        }

        printf("Case %d: ", cont++);
        solve();
    }
}