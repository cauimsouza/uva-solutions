#include <bits/stdc++.h>
using namespace std;

const long long inf  = 1e18;

long long memo[25][25];
int n, an1;

long long solve(int i, int j){
    if(i == n && j == 1)
        return an1;
    long long &a = memo[i][j];
    if(a != -1)
        return a;
    if(i < j){
        a = -inf;
        for(int k = i; k < j; k++)
            a = max(a, solve(i, k) + solve(k + 1, j));
        return a;
    }

    long long b;
    if(i == n)
        b = 0;
    else{
        b = -inf;
        for(int k = i + 1; k <= n; k++)
            b = max(b, solve(k, 1) + solve(k, j));
    }

    long long c;
    if(j == 1)
        c = 0;
    else{
        c = -inf;
        for(int k = 1; k < j; k++)
            c = max(c, solve(i, k) + solve(n, k));
    }

    return a = b + c;
}

int main(){
   while(scanf("%d %d", &n, &an1) != EOF){
        memset(memo, -1, sizeof memo);
        printf("%lld\n", solve(1, n));
   }
}