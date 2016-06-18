#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAXN = 100;
const int INF = 1000;

int res[MAXN][MAXN];
vi path;
int maxFlow, flow, source = 0, sink = MAXN - 1;

void augment(int v, int minEdge){
    if(v == source){
        flow = minEdge;
        return;
    }
    else if(path[v] != -1){
        augment(path[v], min(minEdge, res[path[v]][v]));
        res[path[v]][v] -= flow;
        res[v][path[v]] += flow;
    }
}

int main(){
    vector<vi> adjList;
    map<string , int> mapa;
    mapa["XXL"] = 1;
    mapa["XL"]  = 2;
    mapa["L"]   = 3;
    mapa["M"]   = 4;
    mapa["S"]   = 5;
    mapa["XS"]  = 6;
    int testCases;
    cin >> testCases;

    while(testCases--){
        // cleaning the data
        memset(res, 0, sizeof res);
        adjList.assign(MAXN, vi());

        // reading input
        int numShirts, numVol;
        cin >> numShirts >> numVol;
        for(int i = 1; i <= 6; i++){
            adjList[i].push_back(sink);
            adjList[sink].push_back(i);
            res[i][sink] = numShirts / 6;
        }
        for(int i = 1; i <= numVol; i++){
            string size1, size2;
            cin >> size1 >> size2;
            adjList[mapa[size1]].push_back(6 + i);
            adjList[mapa[size2]].push_back(6 + i);
            adjList[6 + i].push_back(mapa[size1]);
            adjList[6 + i].push_back(mapa[size2]);
            adjList[source].push_back(6 + i);
            adjList[6 + i].push_back(source);
            res[6 + i][mapa[size1]] = INF;
            res[6 + i][mapa[size2]] = INF;
            res[source][6 + i] = 1;
        }

        // running Edmond-Karp's algorithm
        maxFlow = 0;
        bitset<MAXN> bs;
        while(1){
            bs.reset();
            bs.set(source);
            path.assign(MAXN, -1);
            queue<int> q;
            q.push(source);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                if(u == sink)
                    break;
                for(int i = 0; i < (int) adjList[u].size(); i++){
                    int v = adjList[u][i];
                    if(bs[v] == 0 && res[u][v] > 0){
                        q.push(v);
                        bs[v] = 1;
                        path[v] = u;
                    }
                }
            }
            flow = 0;
            augment(sink, INF);
            if(flow == 0)
                break;
            maxFlow += flow;
        }

        if(maxFlow == numVol)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
