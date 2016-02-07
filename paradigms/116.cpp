#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main(){
    int r, c;
    int dp[15][105];
    int path[15][105];
    int A[15][105];
    while(scanf("%d %d", &r, &c) != EOF){
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++)
                scanf("%d", &A[i][j]);

        for(int i = 0; i < r; i++) // cleaning the dp table 
            for(int j = 0; j < c; j++)
                dp[i][j] = inf;

        for(int i = 0; i < r; i++)
            dp[i][c - 1] = A[i][c - 1];// base case

        for(int j = c - 2; j >= 0; j--){
            for(int i = 0; i < r; i++){
                dp[i][j] = inf;
                for(int k = -1; k <= 1; k++){
                    if(dp[(i+k+r)%r][j + 1] < dp[i][j] || (dp[(i+k+r)%r][j + 1] == dp[i][j] && path[i][j] > (i+k+r)%r)){
                        dp[i][j] = dp[(i+k+r)%r][j + 1];
                        path[i][j] = (i+k+r)%r;
                    }
                }
                dp[i][j] += A[i][j];
            }
        }

        int i = 0;
        for(int j = 1; j < r; j++)
            if(dp[j][0] < dp[i][0]) i = j;

        printf("%d", i + 1);
        int k = path[i][0];
        for(int j = 1; j < c; j++){
            printf(" %d", k + 1);
            k = path[k][j];
        }
        printf("\n%d\n", dp[i][0]);
    }
}
