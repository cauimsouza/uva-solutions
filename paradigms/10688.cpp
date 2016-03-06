#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int k;
int memo[505][505];

int solve(int inicio, int fim){
    if(inicio >= fim)
        return 0;
    int &a = memo[inicio][fim];
    if(a != -1)
        return a;
    a = inf;
    for(int i = inicio; i <= fim; i++){
        int aux = (k + i) * (fim - inicio + 1);
        aux += solve(inicio, i - 1);
        aux += solve(i + 1, fim);
        a = min(a, aux); 
    }
    return a;
}

int main(){
   int t;
   scanf("%d", &t);
   for (int i = 0; i < t; ++i)
   {
       int n;
       scanf("%d %d", &n, &k);
       memset(memo, -1, sizeof memo);
       printf("Case %d: %d\n", i + 1, solve(1, n));
   }
}