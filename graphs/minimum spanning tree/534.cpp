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

vi X, Y;
inline int squareDist(int i, int j){
    return (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
}

int main(){
    vector< pair<int, ii> > EdgeList;
    vector<vii> AdjList; 
    int v, k = 1;

    while(scanf("%d", &v), v){
        EdgeList.clear();
        AdjList.assign(v, vii());
        X.resize(v);
        Y.resize(v);

        for(int i = 0; i < v; i++)
            scanf("%d %d", &X[i], &Y[i]);

        for(int i = 0; i < v; i++)
            for(int j = i + 1; j < v; j++)
                EdgeList.push_back(make_pair(squareDist(i, j), ii(i, j)));

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

        printf("Scenario #%d\n", k++);

        queue<ii> q;
        vi color(v, 0);
        bool found = false;
        q.push(ii(0, 0));
        color[0] = 1;
        while(!found){
            ii front = q.front();
            q.pop();
            for(int i = 0; i < sz(AdjList[front.first]); i++){
                ii next = AdjList[front.first][i];
                if(color[next.first] == 0){
                    color[next.first] = 1;
                    int minimax = max(front.second, next.second);
                    q.push(ii(next.first, minimax));
                    if(next.first == 1){
                        printf("Frog Distance = %.3f\n\n", sqrt(minimax));
                        found = true;
                        break;
                    }
                }
            }
        }
    }   
}