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

vector< pair<double, ii> > EdgeList;
vector<double> X, Y; 

int main(){
    
    int TC;
    cin >> TC;
    for(int Counter = 1; Counter <= TC; Counter++){
        int v;
        scanf("%d", &v);
        
        X.resize(v);
        Y.resize(v);
        for(int i = 0; i < v; i++)
            scanf("%lf %lf", &X[i], &Y[i]);

        EdgeList.clear();
        for(int i = 0; i < v; i++)
            for(int j = i + 1; j < v; j++)
                EdgeList.push_back(make_pair(hypot(X[i] - X[j], Y[i] - Y[j]), ii(i, j)));
        sort(EdgeList.begin(), EdgeList.end());

        double mst_cost = 0;
        UnionFind UF(v);
        for(int i = 0; i < sz(EdgeList); i++){
            pair<double, ii> front = EdgeList[i];
            int u = front.second.second, x = front.second.first;
            double w = front.first;
            if(UF.isSameSet(u, x))
                continue;
            UF.unionSet(u, x);
            mst_cost += w;
        }
        
        if(Counter > 1)
            printf("\n");
        printf("%.2f\n", mst_cost); 
    }   
}