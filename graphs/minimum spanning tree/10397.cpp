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

vi x, y;

inline int square(int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int main(){
    vector< pair<int, ii> > EdgeList;
    int v;
    while(scanf("%d", &v) != EOF){
        EdgeList.clear();
        x.resize(v);
        y.resize(v);

        for(int i = 0; i < v; i++)
            scanf("%d %d", &x[i], &y[i]);

        for(int i = 0; i < v; i++)
            for(int j = i + 1; j < v; j++)
                EdgeList.push_back(make_pair(square(i, j), ii(i, j)));

        sort(EdgeList.begin(), EdgeList.end());

        UnionFind UF(v);
        int e;
        scanf("%d", &e);
        while(e--){
            int a, b;
            scanf("%d %d", &a, &b);
            UF.unionSet(a - 1, b - 1);
        }

        int i = 0;
        double msg_cost = 0;
        while(UF.numDisjointSets() > 1){
            auto front = EdgeList[i++];
            int u = front.second.first, v = front.second.second, w = front.first;
            if(UF.isSameSet(u, v))
                continue;
            UF.unionSet(u, v);
            msg_cost += sqrt(w);
        }

        printf("%.2f\n", msg_cost);
    }
}