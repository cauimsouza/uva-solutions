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
vi X, Y; 

inline int squareDist(int i, int j){
    return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) *  (Y[i] - Y[j]);
} 

int main(){
    
    int TC;
    cin >> TC;
    for(int Counter = 1; Counter <= TC; Counter++){
        int v, r;
        scanf("%d %d", &v, &r);
        
        X.resize(v);
        Y.resize(v);
        for(int i = 0; i < v; i++)
            scanf("%d %d", &X[i], &Y[i]);

        EdgeList.clear();
        for(int i = 0; i < v; i++)
            for(int j = i + 1; j < v; j++)
                EdgeList.push_back(make_pair(squareDist(i,j), ii(i, j)));
        sort(EdgeList.begin(), EdgeList.end());

        double streetLength = 0, railwayLength = 0;
        int states = 1;
        UnionFind UF(v);
        for(int i = 0; i < sz(EdgeList); i++){
            pair<int, ii> front = EdgeList[i];
            int u = front.second.second, x = front.second.first, w = front.first;
            if(UF.isSameSet(u, x))
                continue;
            UF.unionSet(u, x);
            if(w > r * r){
                states++;
                railwayLength += sqrt(w);
            }
            else
                streetLength += sqrt(w);
        }
        
        printf("Case #%d: %d %ld %ld\n", Counter, states, lround(streetLength), lround(railwayLength)); 
    }   
}