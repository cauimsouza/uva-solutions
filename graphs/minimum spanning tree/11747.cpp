#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())
using vi = vector<int>;
using ii = pair<int,int>;

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

vector< pair<int, ii> > EdgeList; 

int main(){
    int v, e;
    while(scanf("%d %d", &v, &e), v){
        EdgeList.clear();

        for(int i = 0; i < e; i++){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            EdgeList.push_back(make_pair(w, ii(u,v)));
        }

        sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(v);
        vi heavy;
        for(int i = 0; i < e; i++){
            pair<int, ii> front = EdgeList[i];
            int u = front.second.first, v = front.second.second, w = front.first;
            if(UF.isSameSet(u, v))
                heavy.push_back(w);
            else
                UF.unionSet(u, v);
        }

        if(heavy.empty())
            printf("forest\n");
        else{
            printf("%d",heavy[0]);
            for(int i = 1; i < sz(heavy); i++)
                printf(" %d", heavy[i]);
            printf("\n");
        }
    }
}