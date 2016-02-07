#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
long long memo[70][70][2];
int n, s;

long long solve(int id, int rem, int locked){
    if(rem < 0)
        return 0;
    if(id == n){
        if(rem == 0)
            return 1;
        else
            return 0;
    }
    long long &a = memo[id][rem][locked];
    if(a != -1)
        return a;
    if(locked)
        a = solve(id + 1, rem - 1, 1) + solve(id + 1, rem, 0);
    else
        a = solve(id + 1, rem, 1) + solve(id + 1, rem, 0);
    return a;
}

int main(){
     while(true){
        scanf("%d %d", &n, &s);
        if(n < 0)
            break;
        memset(memo, -1, sizeof memo);
        long long ans = solve(0, s, 1);
        printf("%lld\n", ans);
     }
}