#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main(){
    int dp[110][110];
    int mid[110][110];
    int n, l;
    int A[55];
    while(scanf("%d", &l), l){
        scanf("%d", &n);
        A[0] = 0;
        A[n + 1] = l;
        for(int i = 1; i <= n; i++) scanf("%d", &A[i]);


        for(int i = 0; i <= n; i++){ // base case
            dp[i][i+1] = 0;
            dp[i][i+2] = A[i+2] - A[i];
            mid[i][i+2] = i + 1;
        }
        
        for(int k = 3; k <= n + 1; k++){ // length of the interval being considered
            for(int i = 0; i + k <= n + 1; i++){
                int lo = inf;
                int left = mid[i][i+k-1]; // Knuth-Yao trick
                int right = mid[i+1][i+k];
                for(int j = left; j <= right; j++){
                    if(dp[i][j] + dp[j][i+k] < lo){
                        lo = dp[i][j] + dp[j][i+k];
                        mid[i][i+k] = j;
                    }
                }
                dp[i][i+k] = lo + A[i+k] - A[i];
            }
        }

        printf("The minimum cutting is %d.\n", dp[0][n + 1]);
    }
}
