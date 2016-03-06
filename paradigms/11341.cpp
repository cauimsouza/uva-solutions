#include <bits/stdc++.h>
using namespace std;

const int NINF = - 1e9;
const double EPS = 1e-9;

int L[15][105];
int n, m;
int memo[15][105];

int solve(int id, int remH){
    if(id == n)
        return 0;
    if(remH <= 0)
        return NINF;
    int &a = memo[id][remH];
    if(a != -1)
        return a;
    a = NINF;
    for(int j = remH; j > 0 && L[id][j] >= 5; j--)
        a = max(a, L[id][j] + solve(id + 1, remH - j));
    return a;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 1; j <= m; j++)
                scanf("%d", &L[i][j]);
        memset(memo, -1, sizeof memo);
        int ans = solve(0, m);
        if(ans + EPS >= n * 5)
            printf("Maximal possible average mark - %.2f.\n",EPS + ans/(1.0 * n));
        else
            printf("Peter, you shouldn't have played billiard that much.\n");
    }
}