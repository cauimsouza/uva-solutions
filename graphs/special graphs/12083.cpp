#include <queue>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
using namespace std;

using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;

const int INF = 1e9;
const int MAXN = 505;
int flow;
int source;
int sink;
vi p;
int res[MAXN][MAXN];

void solve();
void augment(int, int);

int main()
{
	int casos;
	cin >> casos;
	while(casos--)
		solve();

	return 0;
}

void solve()
{
	int n;
	scanf("%d", &n);
	vi alturaH;
	vi alturaM;
	vs musicaH;
	vs musicaM;
	vs esporteH;
	vs esporteM;
	for (int i = 0; i < n; ++i)
	{
		int height;
		string sex, music, sport;
		cin >> height >> sex >> music >> sport;
		if(sex == "F")
		{
			alturaM.push_back(height);
			musicaM.push_back(music);
			esporteM.push_back(sport);
		}
		else
		{
			alturaH.push_back(height);
			musicaH.push_back(music);
			esporteH.push_back(sport);
		}
	}

	int homens = (int) alturaH.size();
	int mulher = (int) alturaM.size();
	vvi adjlist(n + 2, vi());
	memset(res, 0, sizeof res);
	source = n;
	sink = n + 1;
	for (int i = 0; i < homens; ++i)
	{
		for (int j = 0; j < mulher; ++j)
		{
			if(abs(alturaH[i] - alturaM[j]) > 40)
				continue;
			if(musicaH[i] != musicaM[j])
				continue;
			if(esporteH[i] == esporteM[j])
				continue;

			adjlist[i].push_back(homens + j);
			adjlist[homens + j].push_back(i);
			res[i][homens + j] = 1; 
		}
		res[source][i] = 1;
		adjlist[source].push_back(i);
		adjlist[i].push_back(source);
	}
	for (int i = 0; i < mulher; ++i)
	{
		adjlist[homens + i].push_back(sink);
		adjlist[sink].push_back(homens + i);
		res[homens + i][sink] = 1;
	}

	int maxflow = 0;
	while(true)
	{
		queue<int> q;
		q.push(source);
		p.assign(n + 2, -1);
		p[source] = source;
		while(!q.empty())
		{
			int u = q.front();
			q.pop();
			if(u == sink)
				break;
			for (int i = 0; i < (int) adjlist[u].size(); ++i)
			{
				int v = adjlist[u][i];
				if(res[u][v] > 0 && p[v] < 0){
					p[v] = u;
					q.push(v);
				}
			}
		}
		flow = 0;
		augment(sink, INF);
		if(flow == 0)
			break;
		maxflow += flow;
	}

	printf("%d\n", n - maxflow);
}

void augment(int u, int minVal)
{
	if(u == source)
	{
		flow = minVal;
		return;
	}
	else if(p[u] != -1)
	{
		augment(p[u], min(minVal, res[p[u]][u]));
		res[p[u]][u] -= flow;
		res[u][p[u]] += flow;
	}
}