#include <bits/stdc++.h>
using namespace std;

int memo[30][30][400];

int solve(int let, int remL, int remS){
    if(remS < 0)
        return 0;
    if(remL == 0){
        if(remS == 0)
            return 1;
        else
            return 0;
    }
    if(let > 26)
        return 0;
    int &a = memo[let][remL][remS];
    if(a != -1)
        return a;
    a = solve(let + 1, remL, remS) + solve(let + 1, remL - 1, remS - let);
    return a;
}

int main(){
    int cont = 1;
    int l, s;
    memset(memo, -1, sizeof memo);
     while(scanf("%d %d", &l, &s), l){
        printf("Case %d: ", cont++);
        int ans;
        if(l > 26 || s > (l*(53 - l))/2)
            ans = 0;
        else
            ans = solve(1, l, s);
        printf("%d\n", ans);
     }
}