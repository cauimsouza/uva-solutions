#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main(){
    int dp[110][110];
    int n, l;
    int A[55];
    while(scanf("%d", &l), l){
        scanf("%d", &n);
        A[0] = 0;
        A[n + 1] = l;
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);


        for(int i = 0; i <= n; i++) // base case
            dp[i][i+1] = 0;
        for(int k = 2; k <= n + 1; k++){ // length of the interval being considered
            for(int i = 0; i + k <= n + 1; i++){
                int lo = inf;
                for(int j = 1; j < k; j++)
                    lo = min(lo, dp[i][i+j] + dp[i+j][i+k]);
                dp[i][i+k] = lo + A[i+k] - A[i];
            }
        }

        printf("The minimum cutting is %d.\n", dp[0][n + 1]);
    }
}
