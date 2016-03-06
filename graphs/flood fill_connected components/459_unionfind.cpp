#include <bits/stdc++.h>
using namespace std;

const bool VISITED = true;
const bool UNVISITED = false;

class UnionFind{
    int rank[30];
    int p[30];
    int numSets;
public:
    bool isSameSet(int i, int j){
        return findSet(i) == findSet(j);
    }
    int findSet(int i){
        if(i == p[i])
            return i;
        return p[i] = findSet(p[i]);
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
    UnionFind(int N){
        numSets = N;
        for(int i = 0; i < N; i++){
            p[i] = i;
            rank[i] = 0;
        }
    }
    int numOfSets(){
        return numSets;
    }
};

int main(){
   int tc;
   scanf("%d\n\n", &tc);
   while(tc--){
        char c;
        scanf("%c", &c);
        UnionFind uf(c - 'A' + 1);

        c = getchar();
        c = getchar();
        while(c != '\n' && c != EOF){
            char v1;
            scanf("%c", &v1);
            uf.unionSet(c - 'A', v1 - 'A');
            c = getchar();
            c = getchar();
        }

        printf("%d\n", uf.numOfSets());
        if(tc)
            printf("\n");
   }
}