#include <bits/stdc++.h>
using namespace std;

inline int raiz(int i){
    return (int)(i - sqrt(i));
}
inline int ln(int i){
    return (int)(log(i));
}
inline int isin(int i){
   return (int)(i * sin(i) * sin(i));
}

int main(){
   int dp[1000010];
   dp[0] = 1;
   dp[1] = 3;
   for(int i = 2; i <= 1000000; i++){
        dp[i] = (dp[raiz(i)] + dp[ln(i)] + dp[isin(i)])%1000000;
   }
   int i;
   while(scanf("%d", &i), (i != -1)){
        printf("%d\n", dp[i]);
   }
}