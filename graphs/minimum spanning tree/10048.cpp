#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())
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

int main(){
    vector< pair<int, ii> > EdgeList;
    vector<vii> AdjList;
    int v, e, q, k = 0;

    while(scanf("%d %d %d", &v, &e, &q), v){
        EdgeList.clear();
        AdjList.assign(v, vii());

        while(e--){
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            EdgeList.push_back(make_pair(w, ii(a - 1, b - 1)));
        }

        sort(EdgeList.begin(), EdgeList.end());

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

        if(k)
            printf("\n");
        printf("Case #%d\n", ++k);
        while(q--){
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;

            vi color(v, 0);
            queue<ii> fila;
            fila.push(ii(a,0));
            color[a] = 1;
            bool found = false;
            while(!fila.empty() && !found){
                ii front = fila.front();
                fila.pop();
                for(int i = 0; i < sz(AdjList[front.first]); i++){
                    ii v = AdjList[front.first][i];
                    if(color[v.first] == 0){
                        color[v.first] = 1;
                        int maxCost = max(front.second, v.second);
                        fila.push(ii(v.first, maxCost));
                        if(v.first == b){
                            printf("%d\n", maxCost);
                            found = true;
                            break;
                        }
                    }
                }
            }
            if(!found)
                printf("no path\n"); 
        }
    }   
}