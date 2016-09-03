#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAXR = 45;
const int MAXC = 15;
const int dr[] = {1,0,-1,0};
const int dc[] = {0,1,0,-1};

using vi = vector<int>;
using vvi = vector<vi>;

int h, w;
int left, right;
char grid[MAXR][MAXC];
int side[MAXR][MAXC]; // 0 - left, 1 - right
int number[MAXR][MAXC];
vvi adjList;
vi match, vis;


void floodfill(int r, int c, int s){
	if(r < 0 || r >= h || c < 0 || c >= w || grid[r][c] != '*' || side[r][c] != -1)
		return;
	grid[r][c] = 'v';
	side[r][c] = s;
	if(s)
		number[r][c] = right++;
	else
		number[r][c] = left++;
	for(int k = 0; k < 4; k++)
		floodfill(r + dr[k], c + dc[k], 1 - s);
}

void addEdge(int r, int c){
	int numLeft = number[r][c];
	for(int k = 0; k < 4; k++){
		int i = r + dr[k], j = c + dc[k];
		if(i < 0 || i >= h || j < 0 || j >= w || grid[i][j] != 'v')
			continue;
		int numRight = left + number[i][j];
		adjList[numLeft].push_back(numRight);
	}
}

int Aug(int u){
	if(vis[u])
		return 0;
	vis[u] = 1;
	for(int i = 0; i < (int) adjList[u].size(); i++){
		int v = adjList[u][i];
		if(match[v] == -1 || Aug(match[v])){
			match[v] = u;
			return 1;
		}
	}
	return 0;
}

int main(){
	
	int scens;
	scanf("%d", &scens);
	while(scens--) {
	    
	    scanf("%d %d", &h, &w);
	    for(int i = 0; i < h; i++)
	    	for(int j = 0; j < w; j++)
	    		scanf(" %c", &grid[i][j]);

	    left = right = 0;
	    memset(side, -1, sizeof side);
	    memset(number, -1, sizeof number);
	    for(int i = 0; i < h; i++)
	    	for(int j = 0; j < w; j++)
	    		if(grid[i][j] == '*')
	    			floodfill(i, j, 0);

	    adjList.assign(left, vi());
	    for(int i = 0; i < h; i++)
	    	for(int j = 0; j < w; j++)
	    		if(side[i][j] == 0)
	    			addEdge(i, j);

	    match.assign(left + right, -1);
	    int MCBM = 0;
	    for(int i = 0; i < left; i++){
	    	vis.assign(left, 0);
	    	MCBM += Aug(i);
	    }

	    printf("%d\n", left + right - MCBM);
	}
	return 0;
}