#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

const int INF = 1e9;
const int MAXN = 100 + 5;

int main(){
    int AdjMat[MAXN][MAXN];
    map<int, int> id;
    int a, b, Case = 1;
    while(1){
        scanf("%d %d", &a, &b);
        if(a == 0)
            break;

        id.clear();
        for(int i = 0; i < MAXN; i++){
            for(int j = 0; j < MAXN; j++)
                AdjMat[i][j] = INF;
            AdjMat[i][i] = 0;
            }

        AdjMat[0][1] = 1;
        int cont = 2;
        id[a] = 0;
        id[b] = 1;
        while(1){
            scanf("%d %d", &a, &b);
            if(a == 0)
                break;

            int idx1, idx2;
            if(id.find(a) == id.end())
                id[a] = idx1 = cont++;
            else
                idx1 = id[a];
            if(id.find(b) == id.end())
                id[b] = idx2 = cont++;
            else
                idx2 = id[b];

            AdjMat[idx1][idx2] = 1;
        }

        int v = sz(id);
        for(int k = 0; k < v; k++)
            for(int i = 0; i < v; i++)
                for(int j = 0; j < v; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        int sum = 0;
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                sum += AdjMat[i][j];

        printf("Case %d: average length between pages = %.3f clicks\n", Case++, sum/(v * (v - 1.0)));
    }
}
