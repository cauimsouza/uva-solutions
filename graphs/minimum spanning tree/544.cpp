#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = (int) 1e9;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

class UnionFind{
    vi p, rank;
    int numSets;
public:
    UnionFind(int N){
        numSets = N;
        p.assign(N, 0);
        rank.assign(N, 0);
        for(int i = 0; i < N; i++)
            p[i] = i;
    }
    int findSet(int i){
        if(i == p[i])
            return i;
        return p[i] = findSet(p[i]);
    }
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j){
        int x = findSet(i), y = findSet(j);
        if(x != y){
            numSets--;
            if(rank[x] > rank[y])
                p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
    int numDisjointSets(){
        return numSets;
    }
};

bool ordena(const pair<int, ii>& a, const pair<int, ii>& b){
    if(a.first != b.first)
        return a.first > b.first;
    return true;
}

int main(){
    vector< pair<int, ii> > EdgeList;
    vector<vii> AdjList;
    vector<string> nameList; 
    int v, e, k = 1;

    while(scanf("%d %d", &v, &e), v){
        EdgeList.clear();
        AdjList.assign(v, vii());
        nameList.clear();

        while(e--){
            string city1, city2;
            cin >> city1 >> city2;
        
            int it1 = find(all(nameList), city1) - nameList.begin();
            if(it1 == sz(nameList))
                nameList.push_back(city1);

            int it2 = find(all(nameList), city2) - nameList.begin();
            if(it2 == sz(nameList))
                nameList.push_back(city2);

            int w;
            scanf("%d", &w);
            EdgeList.push_back(make_pair(w, ii(it1, it2)));
        }

        sort(EdgeList.begin(), EdgeList.end(), ordena);

        UnionFind UF(v);
        for(int i = 0; i < sz(EdgeList) && UF.numDisjointSets() > 1; i++){
            pair<int, ii> front = EdgeList[i];
            int u = front.second.first, v = front.second.second, w = front.first;
            if(UF.isSameSet(u, v))
                continue;
            UF.unionSet(u, v);
            AdjList[u].push_back(ii(v, w));
            AdjList[v].push_back(ii(u, w));
        }

        string origem, destino;
        cin >> origem >> destino;
        int id_ini = find(all(nameList), origem) - nameList.begin();
        int id_fim = find(all(nameList), destino) - nameList.begin();

        printf("Scenario #%d\n", k++);

        queue<ii> q;
        vi color(v, 0);
        bool found = false;
        q.push(ii(id_ini, INF));
        color[id_ini] = 1;
        while(!found){
            ii front = q.front();
            q.pop();
            for(int i = 0; i < sz(AdjList[front.first]); i++){
                ii next = AdjList[front.first][i];
                if(color[next.first] == 0){
                    color[next.first] = 1;
                    int maxmini = min(front.second, next.second);
                    q.push(ii(next.first, maxmini));
                    if(next.first == id_fim){
                        printf("%d tons\n\n", maxmini);
                        found = true;
                        break;
                    }
                }
            }
        }
    }   
}