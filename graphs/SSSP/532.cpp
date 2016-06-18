#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

using ii = pair<int,int>;
using iii = pair<int, ii>;

const int INF = 1e9;

int dl[] = {1,-1,0,0,0,0};
int dr[] = {0,0,1,-1,0,0};
int dc[] = {0,0,0,0,1,-1};

int main(){

#ifndef ONLINE_JUDGE
	freopen("entrada","r",stdin);
#endif
	
	char grid[35][35][35];
	int dist[35][35][35];
	int l, r, c;
	while(1){
		scanf("%d %d %d", &l, &r, &c);
		if(l == 0)
			break;

		int sl, sr, sc;
		int x, y, z;
		for(int i = 0; i < l; i++)
			for(int j = 0; j < r; j++)
				for(int k = 0; k < c; k++){
					dist[i][j][k] = -1;
					char c;
					scanf(" %c", &c);
					grid[i][j][k] = c;
					if(c == 'S'){
						sl = i;
						sr = j;
						sc = k;
					}
					if(c == 'E'){
						x = i;
						y = j;
						z = k;
					}
				}

		dist[sl][sr][sc]= 0;
		queue<iii> q;
		q.push(make_pair(sl, ii(sr, sc)));
		while(!q.empty()){
			iii tripla = q.front();
			q.pop();
			int level = tripla.first, row = tripla.second.first, col = tripla.second.second;
			if(grid[level][row][col] == 'E'){
				break;
			}
			for(int i = 0; i < 6; i++){
				int le = level + dl[i],
					ro = row + dr[i],
					co = col + dc[i];
				if(le < 0 || le >= l || ro < 0 || ro >= r || co < 0 || co >= c || dist[le][ro][co] >= 0 ||
					grid[le][ro][co] == '#')
					continue;
				dist[le][ro][co] = dist[level][row][col] + 1;
				q.push(make_pair(le, ii(ro, co))); 
			}
		}

		if(dist[x][y][z] >= 0)
			printf("Escaped in %d minute(s).\n", dist[x][y][z]);
		else
			printf("Trapped!\n");
	}
}