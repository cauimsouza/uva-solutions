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
    int tc;
    int AdjMat[MAXN][MAXN];
    cin >> tc;
    for (int i = 0; i < tc; ++i)
    {
        int v, e;
        scanf("%d %d", &v, &e);
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++)
                AdjMat[i][j] = INF;
            AdjMat[i][i] = 0;
        }
        while(e--){
            int a, b;
            scanf("%d %d", &a, &b);
            AdjMat[a][b] = AdjMat[b][a] = 1;
        }

        for(int k = 0; k < v; k++)
            for(int i = 0; i < v; i++)
                for(int j = 0; j < v; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        int s, d;
        scanf("%d %d", &s, &d);

        int ans = 0;
        for(int i = 0; i < v; i++)
            ans = max(ans, AdjMat[s][i] + AdjMat[i][d]);
        printf("Case %d: %d\n", i + 1, ans);
    }
}
