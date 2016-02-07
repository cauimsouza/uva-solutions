#include <bits/stdc++.h>
using namespace std;

long long memo[55][55][55];

long long solve(int totalLength, int numBars, int maxLength){     
    if(numBars == 1){
        if(maxLength >= totalLength)
            return 1;
        return 0;
    }
    if(maxLength * numBars < totalLength || numBars > totalLength)
        return 0;

    long long &a = memo[totalLength][numBars][maxLength];
    if(a != -1)
        return a;
    a = 0;
    for(int i = 1; i < totalLength && i <= maxLength; i++)
        a += solve(totalLength - i, numBars - 1, maxLength);
    return a;
}


int main(){
   int m, n, k;
   memset(memo, -1, sizeof memo);
   while(scanf("%d %d %d", &n, &k, &m) != EOF){
   
   printf("%lld\n", solve(n, k, m));
    }
}