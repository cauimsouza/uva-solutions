#include <bits/stdc++.h>
using namespace std;

const int inf  = 1e9;

int price[25], qnt[25];
int memo[105];
int m;

int solve(int k){
    if(k <= 0)
        return 0;
    int &a = memo[k];
    if(a != -1)
        return a;
    a = inf;
    for(int i = 0; i < m; i++)
        a = min(a, price[i] + solve(k - qnt[i]));
    return a;
}

int main(){
   int a, b;
   int cont = 1;
   while(scanf("%d.%d %d", &a, &b, &m) != EOF){
        price[0] = 100 * a + b;
        qnt[0] = 1;

        m++;
        for(int i = 1; i < m; i++){
            scanf("%d %d.%d", &qnt[i],&a, &b);
            price[i] = 100 * a + b;
        }

        printf("Case %d:\n", cont++);
        memset(memo, -1, sizeof memo);
        int k;
        char c;
        do{
            scanf("%d%c", &k, &c);
            int ans = solve(k);
            printf("Buy %d for $%d.%02d\n", k, ans/100, ans%100);
        }while(c != '\n');
   }
}