#include <bits/stdc++.h>
using namespace std;

unsigned long long memo[125][65];

unsigned long long solve(int n, int back){
    unsigned long long &a = memo[n+60][back];
    if(a != -1)
        return a;
    if(n <= 1)
        return a = 1;
    a = 1; // this function call
    for(int i = 1; i <= back; i++){
        a += solve(n - i, back);
    }
    return a;
}

int main(){
    int n, back, k = 1;
    memset(memo, -1, sizeof memo);
    while(scanf("%d %d", &n, &back), n < 61){
        printf("Case %d: %llu\n", k++, solve(n, back));
    }
}
