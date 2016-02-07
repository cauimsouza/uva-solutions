#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const int MAXP = 10010;
int memo[MAXN][MAXP], part[MAXN];
int n, x;

int solve(int id, int remP){
    if(id == n) return 0;
    if(id == x - 1) return solve(id + 1, remP);
    int &a = memo[id][remP];
    if(a != -1) return a;
    if(part[id] > remP) return a = solve(id + 1, remP);
    return a = max(solve(id + 1, remP), part[id] + solve(id + 1, remP - part[id]));
}

int main(){
    while(scanf("%d %d", &n, &x), n){
        memset(memo, -1, sizeof memo);
        for(int i = 0; i < n; i++){
            int a, b; scanf("%d.%d", &a, &b);
            part[i] = 100 * a + b;
        }
        int aux = solve(0, 4999);
        printf("%.2f\n", part[x - 1]/(10000.0 - aux) * 100.0);
    }
}
