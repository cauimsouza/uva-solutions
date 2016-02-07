#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n, t;
    int dp[10010];
    int rem[10010];
    while(scanf("%d %d %d", &m, &n, &t) != EOF){
        dp[0] = rem[0] = 0;
        for(int i = 1; i <= t; i++){
            dp[i] = dp[i-1];
            rem[i] = rem[i-1] + 1;
            if(m <= i && rem[i-m] <= rem[i]){
                dp[i] = dp[i-m] + 1;
                rem[i] = rem[i-m];
            }
            if(n <= i && rem[i-n] < rem[i]){
                dp[i] = dp[i-n] +1;
                rem[i] = rem[i-n];
            }
            else if(n <= i && rem[i-n] == rem[i]){
                if(dp[i-n] + 1 > dp[i])
                    dp[i] = dp[i-n] + 1;
            }
        }
        
        printf("%d", dp[t]);
        if(rem[t]) printf(" %d", rem[t]);
        printf("\n");
    }
}