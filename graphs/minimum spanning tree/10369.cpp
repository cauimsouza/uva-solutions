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
    vi X, Y;
    int tc;
    cin >> tc;

    while(tc--){
        int s, v;
        scanf("%d %d", &s, &v);
        EdgeList.clear();
        X.resize(v);
        Y.resize(v);

        for(int i = 0; i < v; i++){
            scanf("%d %d", &X[i], &Y[i]);
        }

        for(int i = 0; i < v; i++)
            for(int j = i + 1; j < v; j++){
                int dist = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
                EdgeList.push_back(make_pair(dist, ii(i, j)));
            }

        sort(EdgeList.begin(), EdgeList.end());

        UnionFind UF(v);
        double heaviest = 0;
        for(int i = 0; i < sz(EdgeList) && UF.numDisjointSets() > s; i++){
            pair<int, ii> front = EdgeList[i];
            int u = front.second.first, v = front.second.second, w = front.first;
            if(UF.isSameSet(u, v))
                continue;
            UF.unionSet(u, v);
            heaviest = sqrt(w);
        }

        printf("%.2f\n", heaviest);
    }   
}