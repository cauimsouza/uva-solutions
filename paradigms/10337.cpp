#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main(){
   int dp[10][1010];
   int wind[10][1010];
   int tc;
   scanf("%d", &tc);
   while(tc--){
      int x;
      scanf("%d", &x);
      x /= 100;
      for(int i = 9; i >= 0; i--){
        for(int j = 0; j < x; j++)
            scanf("%d", &wind[i][j]);
      }

      for(int i = 0; i < 10; i++)
        for(int j = 0; j < x; j++)
            dp[i][j] = inf;
      dp[0][x-1] = 30 - wind[0][x-1];
      dp[1][x-1] = 20 - wind[1][x-1];
      for(int j = x - 2; j >= 0; j--){
        for(int i = 0; i < 10; i++){
            dp[i][j] = inf;
            if(i + 1 < 10)
                dp[i][j] = min(dp[i][j], 60 - wind[i][j] + dp[i+1][j+1]);
            dp[i][j] = min(dp[i][j], 30 - wind[i][j] + dp[i][j+1]);
            if(i > 0)
                dp[i][j] = min(dp[i][j], 20 - wind[i][j] + dp[i-1][j+1]);
        }
      }

      printf("%d\n\n", dp[0][0]); 
   }
}