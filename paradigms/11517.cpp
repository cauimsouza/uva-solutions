#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int MAXN = 105;
const int MAXW = 10010;

int total;
int value[MAXN];
int memo[MAXN][MAXW];
int m;

int solve(int id, int money){
    if(money == 0) return 0;
    if(money < 0 || id >= m) return inf;
    int &a = memo[id][money];
    if(a != -1) return a;
    a = min(solve(id + 1, money), 1 + solve(id + 1, money - value[id]));
    return a;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d", &total, &m);
        for(int i = 0; i < m; i++) scanf("%d", &value[i]);

        memset(memo, -1, sizeof memo);
        int i = total, ans;
        while(true){
            ans = solve(0, i);
            if(ans < inf) break;
            i++;
        }
        printf("%d %d\n", i, ans);
    }
}
