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

        int total_cost = 0;
        while(e--){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            total_cost += w;
            EdgeList.push_back(make_pair(w, ii(u,v)));
        }

        sort(EdgeList.begin(), EdgeList.end());
        int mst_cost = 0, i = 0, Counter = v - 1;
        UnionFind UF(v);
        while(Counter){
            pair<int, ii> front = EdgeList[i++];
            int u = front.second.first, v = front.second.second, w = front.first;
            if(!UF.isSameSet(u, v)){
                UF.unionSet(u, v);
                mst_cost += w;
                Counter--;
            }
        }

        printf("%d\n", total_cost - mst_cost);
    }
}