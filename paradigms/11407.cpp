#include <bits/stdc++.h>
using namespace std;

int memo[10010];
const int inf = 1e9;

int cont(int n){
    if(n == 0)
        return 0;
    
    int &a = memo[n];
    if(a != -1)
        return a;
    a = inf;
    for(int i = 1; i <= (int)sqrt(n); i++)
        a = min(a, 1 + cont(n - i * i));
    return a;
}

int main(){
   memset(memo, -1, sizeof memo);
   int cases;
   scanf("%d", &cases);

   while(cases--){
        int n;
        scanf("%d", &n);
        printf("%d\n", cont(n));
   }
}