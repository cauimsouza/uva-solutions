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
    int tc;
    cin >> tc;

    while(tc--){
        int v, e;
        scanf("%d %d", &v, &e);
        EdgeList.clear();

        for(int i = 0; i < e; i++){
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            EdgeList.push_back(make_pair(w, ii(a-1,b-1)));
        }

        sort(EdgeList.begin(), EdgeList.end());

        UnionFind UF(v);
        int mst_cost = 0;
        vector< pair<int, ii> > MST_Edges;
        for(int i = 0; i < sz(EdgeList); i++){
            pair<int, ii> front = EdgeList[i];
            int u = front.second.first, v = front.second.second, w = front.first;
            if(UF.isSameSet(u, v))
                continue;
            UF.unionSet(u, v);
            mst_cost += w;
            MST_Edges.push_back(front);
        }

        printf("%d ", mst_cost);

        int ans = 1e9;
        for(int j = 0; j < sz(MST_Edges); j++){
            pair<int, ii> eliminated = MST_Edges[j];
            UnionFind UF(v);
            int mst_cost = 0;
            for(int i = 0; i < sz(EdgeList); i++){
                pair<int, ii> front = EdgeList[i];
                if(front == eliminated)
                    continue;
                int u = front.second.first, v = front.second.second, w = front.first;
                if(UF.isSameSet(u, v))
                    continue;
                UF.unionSet(u, v);
                mst_cost += w;
             }
             if(UF.numDisjointSets() == 1 && mst_cost < ans)
                ans = mst_cost;
        }
        printf("%d\n", ans);
    }   
}