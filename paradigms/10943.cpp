#include <bits/stdc++.h>
using namespace std;

const int mod = 1e6;


int main(){
    int n, k;
    int memo[110][110];
    for(int i = 0; i <= 100; i++) memo[0][i] = 0;
    for(int i = 0; i <= 100; i++) memo[1][i] = 1;
    for(int i = 2; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            memo[i][j];
            for(int k = 0; k <= j; k++){
                memo[i][j] += memo[i-1][k];
                memo[i][j] %= mod;
            }
        }
    }
    while(scanf("%d %d", &n, &k), n){
        printf("%d\n", memo[k][n]);
    }
}
